#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree. If tree is NULL, return 0
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowable value for node's data
 * @max: Maximum allowable value for node's data
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (
		is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_balanced_avl - Checks if a binary tree is balanced and a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is balanced and a valid AVL tree, 0 otherwise
 */
int is_balanced_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_balanced_avl(tree->left) && is_balanced_avl(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_balanced_avl(tree));
}
