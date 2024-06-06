#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Define heap_t type No.37 */
typedef struct binary_tree_s heap_t;

/* Binary tree print */
void binary_tree_print(const binary_tree_t *tree);

/* 0. New node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1. Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* 2. Insert right node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* 3. Delete entire binary tree */
void binary_tree_delete(binary_tree_t *tree);

/* 4. Check if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* 5. Check if a node is a root */
int binary_tree_is_root(const binary_tree_t *node);

/* 6. Pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* 7. In-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* 8. Post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* 9. Measure the height of a binary tree */
size_t binary_tree_height(const binary_tree_t *tree);

/* 10. Depth */
size_t binary_tree_depth(const binary_tree_t *tree);

/* 11.Size */
size_t binary_tree_size(const binary_tree_t *tree);

/* 12. Leaves */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* 13. Nodes */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* 14. Balance Factor */
/* size_t binary_tree_height(const binary_tree_t *tree); */
int binary_tree_balance(const binary_tree_t *tree);

/* 15. Is full */
int binary_tree_is_full(const binary_tree_t *tree);

/* 16. Is perfect */
size_t binary_tree_depth(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int check_perfect(const binary_tree_t *tree, size_t depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/* 17. Sibling */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* 18. Uncle */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* 19. Lowest common ancestor  */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second);

/* 20. Level-order traversal  */
/* size_t binary_tree_height(const binary_tree_t *tree); */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* 21. Is complete  */
int binary_tree_is_complete(const binary_tree_t *tree);

/* 22. Rotate left */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* 23. Rotate right */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* 24. Is BST */
int binary_tree_is_bst(const binary_tree_t *tree);

/* 25. BST - Insert  */
typedef struct binary_tree_s bst_t;
bst_t *bst_insert(bst_t **tree, int value);

/* 26. BST - Array to BST */
bst_t *array_to_bst(int *array, size_t size);

/* 27. BST - Search */
bst_t *bst_search(const bst_t *tree, int value);

/* 28. BST - Remove */
bst_t *bst_find_min(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);

/* 30. Is AVL */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);

/* 31. AVL - Insert */
typedef struct binary_tree_s avl_t;
size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
							avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/* 37. Heap - Insert */
heap_t *heapify_up(heap_t *tree);
heap_t *heap_insert(heap_t **root, int value);
void enqueue(heap_t **queue, int *rear, heap_t *node);
heap_t *dequeue(heap_t **queue, int *front);

/* 38. Heap - Array to Binary Heap */
heap_t *array_to_heap(int *array, size_t size);

#endif /* _BINARY_TREES_H_ */
