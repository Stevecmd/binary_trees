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
 * find_insertion_parent - Finds the parent node
 * where the new node should be inserted.
 * @root: The root of the tree.
 *
 * Return: The parent node where the new node should be inserted.
 */
heap_t *find_insertion_parent(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *parent = queue[front++];

		if (!parent->left || !parent->right)
			return (parent);

		queue[rear++] = parent->left;
		queue[rear++] = parent->right;
	}

	return (NULL);  /* Should never reach here if the tree is valid */
}

/**
 * enqueue - Enqueues a node in the queue.
 * @queue: The queue of nodes.
 * @rear: The rear index of the queue.
 * @node: The node to enqueue.
 */
void enqueue(heap_t **queue, int *rear, heap_t *node)
{
	queue[*rear] = node;
	(*rear)++;
}

/**
 * dequeue - Dequeues a node from the queue.
 * @queue: The queue of nodes.
 * @front: The front index of the queue.
 *
 * Return: The dequeued node.
 */
heap_t *dequeue(heap_t **queue, int *front)
{
	heap_t *node = queue[*front];
	(*front)++;
	return (node);
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
	{
		*root = new_node;
		return (new_node);
	}

	parent = find_insertion_parent(*root);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	return (heapify_up(new_node));
}
