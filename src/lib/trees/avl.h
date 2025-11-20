#ifndef avl_h
#define avl_h

#include "universal.h"

/**
 * possible balance-factors of the nodes in a AVL-tree\n
 * `height(right_subtree) - height(left_subtree)`
 */
typedef enum {
  LeftUnbalanced = -2, /**< the left subtree is too high and the node needs to be rebalanced */
  LeftHeavy = -1,      /**< the left subtree is higher than the right */
  Balanced = 0,        /**< both subtrees have the same height */
  RightHeavy = 1,      /**< the right subtree is higher than the left */
  RightUnbalanced = 2, /**< the right subtree is too high and the node needs to be rebalanced */
} BF;

typedef struct {
  void* data;
  struct avl_node* left;
  struct avl_node* right;
  BF bf;
} avl_node;

typedef struct {
  avl_node* root;
  compare_fn compare_fn;
} avl_tree;

#endif
