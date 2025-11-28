#include "avl-helper.c"
#include "avl_internal.h"
#include "mostly-trees.h"
#include "test.c"

int main() {
  avl_tree* t = initialize_avl_tree(int_cmp);
  insert_into_avl_tree(t, new_int(0));
  assert(t->root->bf == Balanced, "root not balanced, even tho its the only node");
  insert_into_avl_tree(t, new_int(1));
  assert(t->root->bf == RightHeavy, "root did not become RightHeavy after inserting right node");
  insert_into_avl_tree(t, new_int(-1));
  assert(t->root->bf == Balanced, "root did not return to Balanced after inserting left node");
}
