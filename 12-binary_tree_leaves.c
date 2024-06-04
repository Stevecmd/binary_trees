#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves
 * in a binary tree.
 *
 * @tree: A pointer to the root node of the tree
 * to count the leaves.
 *
 * Return: The number of leaves in the binary tree,
 * or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively count leaves in subtrees */
	size_t left_leaves = binary_tree_leaves(tree->left);
	size_t right_leaves = binary_tree_leaves(tree->right);

	return (left_leaves + right_leaves);
}

