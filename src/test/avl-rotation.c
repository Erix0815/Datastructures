#include "avl-helper.c"
#include "avl_internal.h"
#include "mostly-trees.h"
#include "test.c"

int main() {
  avl_tree* t;
  t = initialize_avl_tree(int_cmp);
  insert_into_avl_tree(t, new_int(0));
  insert_into_avl_tree(t, new_int(1));
  insert_into_avl_tree(t, new_int(2));
  defer_assert(t->root->bf == Balanced, "tree did not self-balance via simple left-rotation (BF != Balanced)");
  defer_assert(t->root != NULL && t->root->left != NULL && t->root->right != NULL, "tree did not self-balance via simple left-rotation (wrong ponters)");
  end_if_errors();

  t = initialize_avl_tree(int_cmp);
  insert_into_avl_tree(t, new_int(0));
  insert_into_avl_tree(t, new_int(-1));
  insert_into_avl_tree(t, new_int(-2));
  defer_assert(t->root->bf == Balanced, "tree did not self-balance via simple right-rotation (BF != Balanced)");
  defer_assert(t->root != NULL && t->root->left != NULL && t->root->right != NULL, "tree did not self-balance via simple right-rotation (wrong ponters)");
  end_if_errors();

  t = initialize_avl_tree(int_cmp);
  insert_into_avl_tree(t, new_int(0));
  insert_into_avl_tree(t, new_int(2));
  insert_into_avl_tree(t, new_int(1));
  defer_assert(t->root->bf == Balanced, "tree did not self-balance via rightleft-doublerotation (BF != Balanced)");
  defer_assert(t->root != NULL && t->root->left != NULL && t->root->right != NULL, "tree did not self-balance via rightleft-doublerotation (wrong ponters)");
  end_if_errors();

  t = initialize_avl_tree(int_cmp);
  insert_into_avl_tree(t, new_int(0));
  insert_into_avl_tree(t, new_int(-2));
  insert_into_avl_tree(t, new_int(-1));
  defer_assert(t->root->bf == Balanced, "tree did not self-balance via leftright-doublerotation (BF != Balanced)");
  defer_assert(t->root != NULL && t->root->left != NULL && t->root->right != NULL, "tree did not self-balance via leftright-doublerotation (wrong ponters)");
  end_if_errors();
}
