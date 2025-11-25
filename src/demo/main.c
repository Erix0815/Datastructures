#include "mostly-trees.h"
#include <stdio.h>
#include <stdlib.h>

const int NUM = 8;
int int_cmp(void* a, void* b) { return *(int*)b - *(int*)a; }

int main() {
  avl_tree* t = initialize_avl_tree(int_cmp);

  for (int _ = 0; _ < NUM; ++_) {
    int* item = malloc(sizeof(int));
    *item = rand();
    insert_into_avl_tree(t, item);
  }
  // free(t); recursive
  return 0;
}
