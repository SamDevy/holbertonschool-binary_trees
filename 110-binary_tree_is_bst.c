#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Helper function to check BST with min/max constraints
 * @node: Current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *node, long min, long max)
{
	if (!node)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	return (is_bst_helper(node->left, min, node->n) &&
		is_bst_helper(node->right, node->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_helper(tree, LONG_MIN, LONG_MAX));
}
