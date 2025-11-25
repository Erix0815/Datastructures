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

bool insert_into_avl_tree(avl_tree* tree, void* data) {
  avl_insert_result result = insert_into_avl_node(tree->root, tree->cmp_fn, data);
  tree->root = result.node;
  return result.inserted;
}

avl_insert_result insert_into_avl_node(avl_node* node, cmp_fn cmp_fn, void* data) {
  if (node == NULL)
    return (avl_insert_result){initialize_avl_node(data), true, true};
  else {
    avl_insert_result result = {NULL, false, false};
    int cmp = (*cmp_fn)(node->data, data);
    if (cmp < 0) {
      result = insert_into_avl_node(node->left, cmp_fn, data);
      node->left = result.node;
    } else if (cmp > 0) {
      result = insert_into_avl_node(node->right, cmp_fn, data);
      node->right = result.node;
    }

    result.node = node;

    if (result.balance_trace) {
      // balance node if neccessary
      // update balance_trace
    }

    return result;
  }
}
