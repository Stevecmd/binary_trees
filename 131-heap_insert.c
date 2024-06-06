#include "binary_trees.h"

/**
 * heapify_up - Restores the Max Heap property by moving the new node up.
 * @tree: A pointer to the newly inserted node.
 *
 * Return: A pointer to the root of the heap.
 */
heap_t *heapify_up(heap_t *tree)
{
	int temp;

	while (tree->parent && tree->n > tree->parent->n)
	{
		temp = tree->n;
		tree->n = tree->parent->n;
		tree->parent->n = temp;
		tree = tree->parent;
	}
	return (tree);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 * @value: The value to insert.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	parent = *root;
	while (parent->left && parent->right)
	{
		if (parent->left && parent->right &&
			parent->left->left && parent->left->right)
			parent = parent->left;
		else if (parent->right)
			parent = parent->right;
		else
			parent = parent->left;
	}

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	return (heapify_up(new_node));
}
