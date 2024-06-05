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
 * bst_replace_node - Replaces one node with another in the BST
 * @root: Pointer to the root node of the tree
 * @old_node: Pointer to the node to be replaced
 * @new_node: Pointer to the node to replace with
 *
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_replace_node(bst_t *root, bst_t *old_node, bst_t *new_node)
{
	if (old_node->parent == NULL)
		root = new_node;
	else if (old_node == old_node->parent->left)
		old_node->parent->left = new_node;
	else
		old_node->parent->right = new_node;

	if (new_node != NULL)
		new_node->parent = old_node->parent;

	return (root);
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
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
