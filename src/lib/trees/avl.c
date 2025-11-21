#include "avl_internal.h"
#include <stdlib.h>

avl_tree* initialize_avl_tree(cmp_fn cmp_fn) {
  avl_tree* new = malloc(sizeof(avl_tree));
  new->cmp_fn = cmp_fn;
  new->root = NULL;
  return new;
}

avl_node* initialize_avl_node(void* data) {
  avl_node* new = malloc(sizeof(avl_node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  new->bf = Balanced;
  return new;
}

bool insert_into_avl_tree(avl_tree* tree, void* data) { return false; }

avl_insert_result* insert_into_avl_node(avl_node* node, void* data) {
  avl_insert_result* result;
  if (node) {
    result = malloc(sizeof(avl_insert_result));
    result->node = initialize_avl_node(data);
    result->inserted = true;
    result->balance_trace = true;
    return result;
  } else {
    // todo !
    return result;
  }
}
