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
	/* Recursively count the leaves */
	size_t leaves = 0;

	if (tree)
	{
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
