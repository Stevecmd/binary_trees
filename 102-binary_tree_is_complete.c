#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* Array-based queue to store tree nodes */
	const binary_tree_t *queue[1024];
	int front = 0, rear = 0;
	int has_empty_slot = 0;

	/* Return 0 if the tree is NULL */
	if (tree == NULL)
		return (0);

	/* Enqueue the root node */
	queue[rear++] = tree;

	/* Process nodes in level order */
	while (front < rear)
	{
		const binary_tree_t *node = queue[front++];

		if (node == NULL)
		{
			has_empty_slot = 1;  /* Mark that a NULL node has been seen */
		}
		else
		{
			if (has_empty_slot)
			{
				return (0);
			}
			/* Enqueue left and right children */
			queue[rear++] = node->left;
			queue[rear++] = node->right;
		}
	}

	return (1);
}
