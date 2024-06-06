#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST,
 * or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i, j;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* Check for duplicate elements */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		/* If no duplicate found, insert the element into the tree */
		if (j == i)
		{
			if (bst_insert(&root, array[i]) == NULL)
				return (NULL);
		}
	}

	return (root);
}
