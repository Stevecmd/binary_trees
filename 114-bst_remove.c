#include "binary_trees.h"

/**
 * bst_find_min - Finds the minimum node in a BST
 * @node: Pointer to the root node
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *bst_find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (root->parent && root->parent->left == root)
				root->parent->left = temp;
			else if (root->parent && root->parent->right == root)
				root->parent->right = temp;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (root->parent && root->parent->left == root)
				root->parent->left = temp;
			else if (root->parent && root->parent->right == root)
				root->parent->right = temp;
			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
