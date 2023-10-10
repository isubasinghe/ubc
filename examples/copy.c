#define SIZE 512
#define NULL ((void *)0)

#define MUX_RX_CH 0
#define CLIENT_CH 1

#define BUF_SIZE 2048
#define NUM_BUFFERS 512
#define SHARED_DMA_SIZE (BUF_SIZE * NUM_BUFFERS)

typedef unsigned long int uintptr_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

/* Buffer descriptor */
typedef struct buff_desc {
    uintptr_t encoded_addr; /* encoded dma addresses */
    unsigned int len; /* associated memory lengths */
    void *cookie; /* index into client side metadata */
} buff_desc_t;

/* Circular buffer containing descriptors */
typedef struct ring_buffer {
    uint32_t write_idx;
    uint32_t read_idx;
    uint32_t size;
    char notify_writer;
    char notify_reader;
    buff_desc_t buffers[SIZE];
} ring_buffer_t;

/* A ring handle for enqueing/dequeuing into  */
typedef struct ring_handle {
    ring_buffer_t *free_ring;
    ring_buffer_t *used_ring;
} ring_handle_t;

ring_buffer_t rx_free_mux;
ring_buffer_t rx_used_mux;

uintptr_t rx_free_cli;
uintptr_t rx_used_cli;

uintptr_t shared_dma_vaddr_mux;
uintptr_t shared_dma_vaddr_cli;
uintptr_t uart_base;

ring_handle_t rx_ring_mux;
ring_handle_t rx_ring_cli;



void ring_init(ring_handle_t *ring, ring_buffer_t *free, ring_buffer_t *used, int buffer_init, uint32_t free_size, uint32_t used_size)
{
    ring->free_ring = free;
    ring->used_ring = used;

    if (buffer_init) {
        ring->free_ring->write_idx = 0;
        ring->free_ring->read_idx = 0;
        ring->free_ring->size = free_size;
        ring->free_ring->notify_writer = 0;
        ring->free_ring->notify_reader = 0;
        ring->used_ring->write_idx = 0;
        ring->used_ring->read_idx = 0;
        ring->used_ring->size = used_size;
        ring->used_ring->notify_writer = 0;
        ring->used_ring->notify_reader =  0;
    }
}

static inline char ring_empty(ring_buffer_t *ring)
{
    return !((ring->write_idx - ring->read_idx) % ring->size);
}

static inline char ring_full(ring_buffer_t *ring)
{
    return !((ring->write_idx - ring->read_idx + 1) % ring->size);
}

static inline uint32_t ring_size(ring_buffer_t *ring)
{
    return (ring->write_idx - ring->read_idx);
}



static inline int enqueue(ring_buffer_t *ring, uintptr_t buffer, unsigned int len, void *cookie)
{
    if (ring_full(ring)) {
        return -1;
    }
    uint32_t idx = ring->write_idx % ring->size;
    buff_desc_t *rbufs = (buff_desc_t *)ring->buffers;
    if ((rbufs >= (buff_desc_t *)((0x7fffffff *2U + 1U)/2)) || (idx >= (uint32_t)((0x7fffffff * 2U + 1U)/2))) { return -1; }
    buff_desc_t tmp = *(rbufs + idx);
    ring->buffers[ring->write_idx % ring->size].encoded_addr = buffer;
    ring->buffers[ring->write_idx % ring->size].len = len;
    ring->buffers[ring->write_idx % ring->size].cookie = cookie;

    // THREAD_MEMORY_RELEASE();
    ring->write_idx++;
    
    return 0;

}

static inline int dequeue(ring_buffer_t *ring, uintptr_t *addr, unsigned int *len, void **cookie)
{
    if (ring_empty(ring)) {
        return -1;
    }


    *addr = ring->buffers[ring->read_idx % ring->size].encoded_addr;
    *len = ring->buffers[ring->read_idx % ring->size].len;
    *cookie = ring->buffers[ring->read_idx % ring->size].cookie;

    // THREAD_MEMORY_RELEASE();
    ring->read_idx++;

    return 0;
}

static inline int enqueue_free(ring_handle_t *ring, uintptr_t addr, unsigned int len, void *cookie)
{
    return enqueue(ring->free_ring, addr, len, cookie);
}

static inline int enqueue_used(ring_handle_t *ring, uintptr_t addr, unsigned int len, void *cookie)
{
    return enqueue(ring->used_ring, addr, len, cookie);
}

static inline int dequeue_free(ring_handle_t *ring, uintptr_t *addr, unsigned int *len, void **cookie)
{
    return dequeue(ring->free_ring, addr, len, cookie);
}

static inline int dequeue_used(ring_handle_t *ring, uintptr_t *addr, unsigned int *len, void **cookie)
{
    return dequeue(ring->used_ring, addr, len, cookie);
}

void sel4cp_notify(unsigned int ch) {
}

void sel4cp_notify_delayed(unsigned int ch) {
}

uintptr_t m_addr = 0;
uintptr_t c_addr = 0;
unsigned int m_len = 0;
unsigned int c_len = 0;

void *cookie = NULL;
void *cookie2 = NULL;

void memcpy(char *src, char *dest, unsigned long long len) {}

void process_rx_complete(void)
{
    uint64_t enqueued = 0;
    // We only want to copy buffers if all the dequeues and enqueues will be successful
    while (!ring_empty(rx_ring_mux.used_ring) &&
            !ring_empty(rx_ring_cli.free_ring) &&
            !ring_full(rx_ring_mux.free_ring) &&
            !ring_full(rx_ring_cli.used_ring)) {

        int err;

        err = dequeue_used(&rx_ring_mux, &m_addr, &m_len, &cookie);
        //assert(!err);
        // get a free one from clients queue.
        err = dequeue_free(&rx_ring_cli, &c_addr, &c_len, &cookie2);
        //assert(!err);
        if (!c_addr ||
                c_addr < shared_dma_vaddr_cli ||
                c_addr >= shared_dma_vaddr_cli + SHARED_DMA_SIZE)
        {
          char *x = (char *)NULL;
          *x = 'a';
        }

        if (c_len < m_len) {
          char *x = (char *)NULL;
          *x = 'a';
        }
        // copy the data over to the clients address space.
        memcpy((void *)c_addr, (void *)m_addr, m_len);

        /* Now that we've copied the data, enqueue the buffer to the client's used ring. */
        err = enqueue_used(&rx_ring_cli, c_addr, m_len, cookie2);
        //assert(!err);
        /* enqueue the old buffer back to dev_rx_ring.free so the driver can use it again. */
        err = enqueue_free(&rx_ring_mux, m_addr, BUF_SIZE, cookie);
        //assert(!err);

        enqueued += 1;
    }

    if (!ring_empty(rx_ring_mux.used_ring)) {
        // we want to be notified when this changes so we can continue
        // enqueuing packets to the client.
        rx_ring_cli.free_ring->notify_reader = 0;
    } else {
        rx_ring_cli.free_ring->notify_reader =  0;
    }

    if (rx_ring_cli.used_ring->notify_reader && enqueued) {
        sel4cp_notify(CLIENT_CH);
    }

    /* We want to inform the mux that more free buffers are available */
    if (enqueued && rx_ring_mux.free_ring->notify_reader) {
        sel4cp_notify_delayed(MUX_RX_CH);
    }
}

//void notified(int ch)
// requires (ch >= 0) && (ch <= 63);
// ensures 0;
//{
    /* We have one job. */
//    process_rx_complete();
//}

