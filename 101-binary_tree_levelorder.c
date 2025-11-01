#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 *
 * Description: Calls func for each node's value in level-order (BFS).
 *              If tree or func is NULL, does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, h;

	if (!tree || !func)
		return;

	/* Get height of the tree */
	h = binary_tree_height(tree);

	/* Traverse each level */
	for (i = 0; i <= h; i++)
	{
		level_helper(tree, func, i);
	}
}

/**
 * level_helper - helper function to print nodes at a given level
 * @tree: pointer to the current node
 * @func: function to call for node value
 * @level: current level to print
 */
void level_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		level_helper(tree->left, func, level - 1);
		level_helper(tree->right, func, level - 1);
	}
}
