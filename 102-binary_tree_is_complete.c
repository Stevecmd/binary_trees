#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * queue_push - Pushes a binary tree node into a queue.
 *
 * @queue: A pointer to the head of the queue.
 * @node: A pointer to the binary tree node to push.
 * Return: A pointer to the modified queue.
 */
queue_t *queue_push(queue_t *queue, const binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	queue_t *temp = queue;

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	if (queue == NULL)
		return (new_node);

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;
	return (queue);
}

/**
 * queue_pop - Pops a node from the front of a queue.
 *
 * @queue: A pointer to the head of the queue.
 * Return: A pointer to the modified queue.
 */
queue_t *queue_pop(queue_t *queue)
{
	queue_t *temp;

	if (queue == NULL)
		return (NULL);

	temp = queue->next;
	free(queue);
	return (temp);
}

/**
 * queue_free - Frees a queue.
 *
 * @queue: A pointer to the head of the queue.
 */
void queue_free(queue_t *queue)
{
	queue_t *temp;

	while (queue != NULL)
	{
		temp = queue->next;
		free(queue);
		queue = temp;
	}
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	queue_t *queue = NULL;
	int is_complete = 1, has_empty_slot = 0;

	queue = queue_push(queue, tree);

	while (queue != NULL)
	{
		const binary_tree_t *node = queue->node;

		queue = queue_pop(queue);

		if (node == NULL)
			has_empty_slot = 1;
		else
		{
			if (has_empty_slot)
			{
				is_complete = 0;
				break;
			}
			queue = queue_push(queue, node->left);
			queue = queue_push(queue, node->right);
		}
	}

	queue_free(queue);
	return (is_complete);
}
