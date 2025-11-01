#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/* 0. New node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1. Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* 2. Insert right */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* 3. Delete */
void binary_tree_delete(binary_tree_t *tree);

/* 4. Is leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* 5. Is root */
int binary_tree_is_root(const binary_tree_t *node);

/* 6. Pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* 7. In-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* 8. Post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* 9. Height */
size_t binary_tree_height(const binary_tree_t *tree);

/* 10. Depth */
size_t binary_tree_depth(const binary_tree_t *tree);

/* 11. Size */
size_t binary_tree_size(const binary_tree_t *tree);

/* 12. Leaves */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* 13. Nodes */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Provided print function (optional, for visualization) */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
