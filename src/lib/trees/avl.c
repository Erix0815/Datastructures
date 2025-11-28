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

avl_node* rotatle_left(avl_node* node) {
  avl_node* pivot = node->right;
  if (pivot->bf == Balanced) {
    node->bf = RightHeavy;
    pivot->bf = LeftHeavy;
  } else {
    node->bf = Balanced;
    pivot->bf = Balanced;
  }
  node->right = pivot->left;
  pivot->left = node;
  return pivot;
}
avl_node* rotatle_right(avl_node* node) {
  avl_node* pivot = node->left;
  if (pivot->bf == Balanced) {
    node->bf = LeftHeavy;
    pivot->bf = RightHeavy;
  } else {
    node->bf = Balanced;
    pivot->bf = Balanced;
  }
  node->left = pivot->right;
  pivot->right = node;
  return pivot;
}
avl_node* rotatle_rightleft(avl_node* node) {
  avl_node* pivot = node->right->left;
  if (pivot->bf == RightHeavy) {
    node->bf = LeftHeavy;
    node->right->bf = Balanced;
  } else if (pivot->bf == LeftHeavy) {
    node->bf = Balanced;
    node->right->bf = RightHeavy;
  } else {
    node->bf = Balanced;
    node->right->bf = Balanced;
  }
  node->right->left = pivot->right;
  pivot->right = node->right;
  node->right = pivot->left;
  pivot->left = node;
  return pivot;
}
avl_node* rotatle_leftright(avl_node* node) {
  avl_node* pivot = node->left->right;
  if (pivot->bf == LeftHeavy) {
    node->bf = RightHeavy;
    node->right->bf = Balanced;
  } else if (pivot->bf == RightHeavy) {
    node->bf = Balanced;
    node->right->bf = LeftHeavy;
  } else {
    node->bf = Balanced;
    node->right->bf = Balanced;
  }
  node->left->right = pivot->left;
  pivot->left = node->left;
  node->left = pivot->right;
  pivot->right = node;
  return pivot;
}
