#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return temp;
		}

		bst_t *temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;

		root->n = temp->n;

		if (temp->parent->left == temp)
			temp->parent->left = temp->right;
		else
			temp->parent->right = temp->right;

		if (temp->right != NULL)
			temp->right->parent = temp->parent;

		free(temp);
	}

	return root;
}
