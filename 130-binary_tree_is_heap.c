#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * is_max_heap - Checks if a binary tree is a max heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	return (is_complete(tree, 0, size) && is_max_heap(tree));
}
