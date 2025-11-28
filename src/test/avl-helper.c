#include <stdlib.h>

int int_cmp(void* a, void* b) { return *(int*)b - *(int*)a; }
int* new_int(int i) {
  int* new = malloc(sizeof(int));
  *new = i;
  return new;
}
