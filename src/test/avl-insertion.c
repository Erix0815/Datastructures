#include "avl-helper.c"
#include "avl_internal.h"
#include "mostly-trees.h"
#include "test.c"

int main() {
  avl_tree* t = initialize_avl_tree(int_cmp);
  insert_into_avl_tree(t, new_int(0));
  assert(t->root != NULL, "insertion of root-node (0) failed");
  insert_into_avl_tree(t, new_int(2));
  assert(t->root->right != NULL, "binary-tree not sorted correctly (_2_ > 0)");
  insert_into_avl_tree(t, new_int(-2));
  assert(t->root->left != NULL, "binary-tree not sorted correctly (0 > _-2_)");
  insert_into_avl_tree(t, new_int(3));
  assert(t->root->right->right != NULL, "binary-tree not sorted correctly (_3_ > 2 > 0)");
  insert_into_avl_tree(t, new_int(1));
  assert(t->root->right->left != NULL, "binary-tree not sorted correctly (2 > _1_ > 0)");
}
