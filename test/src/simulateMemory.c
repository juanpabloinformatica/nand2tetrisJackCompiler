#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEMORY_HEAP_LENGTH (100)
#define UNINITIALIZED_DEFAULT_VALUE (-99)
#define AVAILABLE_SPACE UNINITIALIZED_DEFAULT_VALUE
#define WAIT                                                                   \
  {                                                                            \
    int x;                                                                     \
    scanf("%d", &x);                                                           \
  }
static int counter = 0;
static void fill_memory_block(long int address, int value) {

  long int *p_address = (long int *)address;
  for (size_t i = 2; i <= p_address[1]; i++) {

    p_address[i] = (value == -1) ? counter : value;
  }

  if (value == -1)
    counter++;
}
struct memory_heap {

  /*this will point to the first element of the simulated heap*/
  /*I will have to turn the mem adress to int* */
  long int *heap;
  long int *free_list;
  int length;
  long int (*alloc)(struct memory_heap *mem_heap, int size);
  void (*dealloc)(struct memory_heap *mem_heap, long int address);
};

long int alloc(struct memory_heap *mem_heap, int size) {
  long int *temp_node = mem_heap->free_list;
  long int block = -1;
  while (temp_node != NULL) {
    if (size <= temp_node[1]) {
      block = (long int)&(mem_heap->heap[temp_node[1] + 1 - (size + 2)]);
      ((long int *)block)[0] = (long int)NULL;
      ((long int *)block)[1] = size + 2;
      break;
    }
    temp_node = (long int *)(temp_node[0]);
  }
  if (block == -1)
    printf("No more free memory\n");

  temp_node[1] -= (size + 2);
  // assert(block == (long int)&mem_heap->heap[88]);
  return block;
}
void dealloc(struct memory_heap *mem_heap, long int address) {
  long int *p_address = (long int *)address;
  /*for re-setting the liberate place */
  fill_memory_block(address, AVAILABLE_SPACE);
  /**/

  *p_address = mem_heap->free_list[0];
  mem_heap->free_list[0] = address;
  return;
}

void memory_heap_destroy(struct memory_heap *mem_heap) {
  if (!mem_heap)
    return;
  if (mem_heap->heap)
    free(mem_heap->heap);
}
void memory_heap_init(struct memory_heap *mem_heap) {
  if (!mem_heap)
    return;

  mem_heap->heap = (long int *)malloc(sizeof(long int) * MEMORY_HEAP_LENGTH);

  for (int i = 0; i < MEMORY_HEAP_LENGTH; i++)
    mem_heap->heap[i] = UNINITIALIZED_DEFAULT_VALUE;

  mem_heap->free_list = mem_heap->heap;
  mem_heap->length = MEMORY_HEAP_LENGTH - 2;
  mem_heap->heap[0] = (long int)NULL;
  mem_heap->heap[1] = mem_heap->length;
  mem_heap->alloc = alloc;
  mem_heap->dealloc = dealloc;
}

int main() {
  struct memory_heap mh;
  memory_heap_init(&mh);
  long int memory_block_1 = mh.alloc(&mh, 10);
  long int memory_block_2 = mh.alloc(&mh, 45);
  long int memory_block_3 = mh.alloc(&mh, 20);
  fill_memory_block(memory_block_1, -1);
  fill_memory_block(memory_block_2, -1);
  fill_memory_block(memory_block_3, -1);
  mh.dealloc(&mh, memory_block_1);
  mh.dealloc(&mh, memory_block_2);
  // mh.dealloc(&mh, memory_block_3);

  memory_heap_destroy(&mh);
  /*for debuggin*/

  WAIT;
}
