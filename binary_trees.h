#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

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
#endif /* _BINARY_TREES_H_ */

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
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* 20. Level-order traversal  */
size_t binary_tree_height(const binary_tree_t *tree);
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int));
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

