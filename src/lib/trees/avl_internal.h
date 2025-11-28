#ifndef avl_internal_h
#define avl_internal_h

#include "avl.h"
#include "universal.h"

/**
 * \brief possible balance-factors of the nodes in a AVL-tree
 * \details `height(right_subtree) - height(left_subtree)`
 */
typedef enum BF_e {
  LeftUnbalanced = -2, /**< \brief the left subtree is too high and the node needs to be rebalanced */
  LeftHeavy = -1,      /**< \brief the left subtree is higher than the right */
  Balanced = 0,        /**< \brief both subtrees have the same height */
  RightHeavy = 1,      /**< \brief the right subtree is higher than the left */
  RightUnbalanced = 2, /**< \brief the right subtree is too high and the node needs to be rebalanced */
} BF;

/**
 * \brief node used in an \ref avl_tree
 */
struct avl_node_s {
  void* data;      /**< \brief pointer to the data inside the node */
  avl_node* left;  /**< \brief pointer to the left child */
  avl_node* right; /**< \brief pointer to the right child */
  BF bf;           /**< \brief balance-factor of the node */
};

/**
 * \brief creates a new \ref avl_node, without children
 */
avl_node* initialize_avl_node(void* data);

/**
 * \brief a struct containing information needed for updating references in \ref avl_tree and balancing the \ref avl_tree
 */
typedef struct avl_insert_result_s {
  avl_node* node;     /**< \brief the (new) root of the current subtree */
  bool balance_trace; /**< \brief \c true, if the height of the subtree changed */
  bool inserted;      /**< \brief \c false if the tree already contained the inserted data */
} avl_insert_result;

/**
 * \brief insert data into an \ref avl_node
 * \param node root of the current subtree to insert into (can be null, to create and return a leaf-node)
 * \param cmp_fn \ref cmp_fn used inside the tree
 * \param data data to insert
 */
avl_insert_result insert_into_avl_node(avl_node* node, cmp_fn cmp_fn, void* data);

/**
 * \brief left-rotate an \ref avl_node
 * \warning requires the node to be \ref RightUnbalanced and the right child to be \ref Balanced or \ref RightHeavy
 */
avl_node* rotatle_left(avl_node* node);

/**
 * \brief right-rotate an \ref avl_node
 * \warning requires the node to be \ref LeftUnbalanced and the left child to be \ref Balanced or \ref LeftHeavy
 */
avl_node* rotatle_right(avl_node* node);

/**
 * \brief rightleft-doublerotate an \ref avl_node
 * \warning requires the node to be \ref RightUnbalanced and the right child to be \ref LeftHeavy
 */
avl_node* rotatle_rightleft(avl_node* node);

/**
 * \brief leftright-doublerotate an \ref avl_node
 * \warning requires the node to be \ref LeftUnbalanced and the left child to be \ref RightHeavy
 */
avl_node* rotatle_leftright(avl_node* node);

#endif
