#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary tree print */
void binary_tree_print(const binary_tree_t *tree);

/* 0. New node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1. Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* 2. Insert right node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* 3. Delete entire binary tree */
void binary_tree_delete(binary_tree_t *tree);

/* 4. Check if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

#endif /* _BINARY_TREES_H_ */