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
/*@
requires ring_handle_free_ring(ring,_) &*& 
         ring_handle_used_ring(ring, _) &*&
         ring_buffer_write_idx(free,_) &*&
         ring_buffer_read_idx(free, _) &*&
         ring_buffer_size(free, _) &*&
         ring_buffer_notify_writer(free, _) &*&
         ring_buffer_notify_reader(free, _) &*&
         ring_buffer_write_idx(used, _) &*&
         ring_buffer_read_idx(used, _) &*&
         ring_buffer_size(used, _) &*&
         ring_buffer_notify_writer(used, _) &*&
         ring_buffer_notify_reader(used, _);
@*/
//@ensures 0;
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
    /*@
    leak ring_handle_free_ring(ring,_) &*& 
         ring_handle_used_ring(ring, _) &*&
         ring_buffer_write_idx(free,_) &*&
         ring_buffer_read_idx(free, _) &*&
         ring_buffer_size(free, _) &*&
         ring_buffer_notify_writer(free, _) &*&
         ring_buffer_notify_reader(free, _) &*&
         ring_buffer_write_idx(used, _) &*&
         ring_buffer_read_idx(used, _) &*&
         ring_buffer_size(used, _) &*&
         ring_buffer_notify_writer(used, _) &*&
         ring_buffer_notify_reader(used, _);
    @*/
}

static inline char ring_empty(ring_buffer_t *ring)
/*@
requires 
	ring_buffer_write_idx(ring, ?widx) &*& 
	ring_buffer_read_idx(ring, ?ridx) &*&
	widx >= ridx &*&  (widx >= 0) &*& ((widx - ridx) <= 4294967295) &*&
	ring_buffer_size(ring, ?size) &*& size > 0;
@*/
/*@
ensures 0;
@*/
{
    return !((ring->write_idx - ring->read_idx) % ring->size);
    //@leak ring_buffer_read_idx(ring, _);
    //@leak ring_buffer_size(ring, _);
    //@leak ring_buffer_write_idx(ring, _);
}

static inline char ring_full(ring_buffer_t *ring)
/*@
requires 
  ring_buffer_write_idx(ring, ?widx) &*&
  ring_buffer_read_idx(ring, ?ridx) &*&
  widx >= ridx &*& ((widx - ridx + 1) <= 4294967295) &*&
  ring_buffer_size(ring, ?size) &*& size > 0;
@*/
/*@
ensures 0;
@*/
{
    //assert((ring->write_idx - ring->read_idx) >= 0);
    return !((ring->write_idx - ring->read_idx + 1) % ring->size);
    //@leak ring_buffer_read_idx(ring, _);
    //@leak ring_buffer_size(ring, _);
    //@leak ring_buffer_write_idx(ring, _);
}

static inline uint32_t ring_size(ring_buffer_t *ring)
/*@
requires 
  ring_buffer_write_idx(ring, ?widx) &*&
  ring_buffer_read_idx(ring, ?ridx) &*&
  (0 <= (widx - ridx)) && ((widx - ridx) <= 4294967295);
@*/
/*@
ensures 0;
@*/
{
    //assert((ring->write_idx - ring->read_idx) >= 0);
    return (ring->write_idx - ring->read_idx);
    //@leak ring_buffer_write_idx(ring, _);
    //@leak ring_buffer_read_idx(ring, _);
}
/*@
predicate characters(char *start, int count) = 
  count <= 0 ? 0 : character(start, _) &*& characters(start+1, count-1);
@*/

/*@
lemma void split_characters_chunk(char *start, int i)
  requires characters(start, ?count) &*& 0 <= i &*& i <= count;
  ensures characters(start, i) &*& characters(start+i, count-i); 
  {
    if(i==0) {
      close characters(start, 0);
    }else {
      open characters(start, count);
      split_characters_chunk(start+1, i-1);
      close characters(start, i);
    }
  }
@*/

/*@ 
lemma void merge_characters_chunk(char *start)
  requires characters(start, ?i) &*& characters(start+i, ?count) &*& 0 <= i &*& 0 <= count;
  ensures characters(start, i + count); {
    open characters(start, i);
    if(i != 0) {
      merge_characters_chunk(start + 1);
      close characters(start, i + count);
    }
  }
@*/

void getchars(char *start, int count) 
/*@
requires characters(start, count) &*& ((((uintptr_t)start) + count) <= UINTPTR_MAX);
@*/
//@ensures characters(start, count);
{
  for(int i=0; i < count; i++) 
  //@ invariant characters(start, count) &*& 0 <= i;
  {
    char c = 'a';
    //@ split_characters_chunk(start, i);
    //@ open characters(start+i, count - i);
    *(start + i) = c;
    //@ close characters(start+i, count-i);
    //@ merge_characters_chunk(start);
  }
}

/*@
predicate buff_desc(buff_desc_t* bs, int idx) = 
  bs[idx] |-> ?b;
@*/

/*@
lemma void assume_fits(buff_desc_t* a, int b) 
requires 0;
ensures 0;
{
  assume(a + b >= 0);	
}
@*/

static inline int enqueue(ring_buffer_t *ring, uintptr_t buffer, unsigned int len, void *cookie)
/*@
requires 
	buffer != 0 &*&
	ring_buffer_write_idx(ring, ?widx) &*&
	ring_buffer_read_idx(ring, ?ridx) &*&
	widx >= ridx &*&
	(widx - ridx + 1) <= 4294967295 &*&
	ring_buffer_size(ring, ?size) &*&
	size > 0 &*&
	ring_buffer_write_idx(ring, ?lwidx) &*&
	ridx <= lwidx &*&
	(lwidx - ridx + 1) <= 4294967295 &*&
	ring_buffer_size(ring, ?lsize) &*&
	lsize > 0 &*&
	ring_buffer_buffers(ring, ?buffers) &*&
	buff_desc(buffers, widx%lsize);
@*/
/*@
ensures 0;
@*/
{
    //assert(buffer != 0);
    if (ring_full(ring)) {
    	//@leak ring_buffer_buffers(ring, _);
    	//@leak buff_desc(buffers, widx%lsize);
    	//@leak ring_buffer_size(ring, _);
    	//@leak ring_buffer_write_idx(ring, _);
        return -1;
    }
    uint32_t idx = ring->write_idx % ring->size;
    buff_desc_t *rbufs = (buff_desc_t *)ring->buffers;
    //@ assume_fits(rbufs, idx);
    if ((rbufs >= (buff_desc_t *)((0x7fffffff *2U + 1U)/2)) || (idx >= (uint32_t)((0x7fffffff * 2U + 1U)/2))) { return -1; }
    //@ assert (rbufs + idx >= 0);
    buff_desc_t tmp = *(rbufs + idx);
    ring->buffers[ring->write_idx % ring->size].encoded_addr = buffer;
    ring->buffers[ring->write_idx % ring->size].len = len;
    ring->buffers[ring->write_idx % ring->size].cookie = cookie;

    // THREAD_MEMORY_RELEASE();
    ring->write_idx++;
    
    //@leak buff_desc(buffers, widx%lsize);
    //@leak ring_buffer_buffers(ring, _);
    
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

