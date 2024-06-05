#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t index = 0, size;
	binary_tree_t **queue = NULL;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (queue == NULL)
		return (0);

	queue[index++] = (binary_tree_t *)tree;

	while (index < size)
	{
		if (queue[index] == NULL)
			break;

		queue[index] = queue[index]->left;
		queue[index + 1] = queue[index]->right;
		index++;
	}

	for (index = 0; queue[index] != NULL; index++)
	{
		if (queue[index]->left != NULL || queue[index]->right != NULL)
		{
			free(queue);
			return (0);
		}
	}

	free(queue);
	return (1);
}
