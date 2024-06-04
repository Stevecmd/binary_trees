#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL, otherwise the height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = 0, right_height = 0;

	/* Calculate the height of the left subtree */
	if (tree->left != NULL)
		left_height = 1 + binary_tree_height(tree->left);

	/* Calculate the height of the right subtree */
	if (tree->right != NULL)
		right_height = 1 + binary_tree_height(tree->right);

	/* Return the height of the taller subtree */
	return (left_height > right_height ? left_height : right_height);
}
