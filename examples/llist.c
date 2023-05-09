#define NULL ((void*)0)

extern void *malloc(long unsigned int sz);

struct node {
  int item;
  struct node *next;
};

int main(int argc, char *argv[]) {
  struct node *head = malloc(sizeof(struct node));
  head->item = 95;
  head->next = NULL;

  struct node *nxt = malloc(sizeof(struct node));
  nxt->item = 23;
  nxt->next = NULL;

  struct node* curr = head;
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = nxt;

  return 0;
}
