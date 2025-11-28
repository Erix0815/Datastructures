#ifndef avl_h
#define avl_h

#include "universal.h"

/**
 * \copydoc avl_node_s
 */
typedef struct avl_node_s avl_node;

/**
 * \brief represents a self-balancing avl-tree
 * \details abstraction over the \ref avl_node \n
 * strores the \ref cmp_fn so it does not have to be explicititly passed to every function
 */
typedef struct avl_tree_s {
  avl_node* root; /**< \brief root \ref avl_node of the tree */
  cmp_fn cmp_fn;  /**< \brief \ref cmp_fn used for items in the tree */
} avl_tree;

/**
 * \brief creates a new \ref avl_tree
 * \param  cmp_fn compare-function that will be used for the elements in the tree
 * \return a new, empty avl-tree, ready for use
 */
avl_tree* initialize_avl_tree(cmp_fn cmp_fn);

/**
 * \brief insert a new item into the tree
 * \param tree the avl-tree to insert into
 * \param data pointer to the item do be added
 * \return \c false if the data-item was already in the tree
 */
bool insert_into_avl_tree(avl_tree* tree, void* data);

#endif
