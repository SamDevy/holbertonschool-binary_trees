#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node
 * @tree: pointer to the node
 *
 * Return: depth, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

/**
 * perfect_helper - checks recursively if tree is perfect
 * @tree: pointer to the node
 * @depth: expected depth of leaves
 * @level: current level of node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int perfect_helper(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (depth == level);

	if (!tree->left || !tree->right)
		return (0);

	return (perfect_helper(tree->left, depth, level + 1) &&
		perfect_helper(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 *
 * Return: 1 if perfect, 0 if not or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = binary_tree_depth(tree->left ? tree->left : tree->right);
	return (perfect_helper(tree, depth, 0));
}
