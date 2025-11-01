#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree
 *                          using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: Uses a queue (FIFO) to traverse the tree
 * level by level. If tree or func is NULL, the function
 * does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	size_t front = 0, back = 0, size = 0;

	if (tree == NULL || func == NULL)
		return;

	size = 1024; /* reasonable fixed queue size */
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (queue == NULL)
		return;

	queue[back++] = tree;

	while (front < back)
	{
		const binary_tree_t *node = queue[front++];

		func(node->n);

		if (node->left)
			queue[back++] = node->left;
		if (node->right)
			queue[back++] = node->right;
	}

	free((void *)queue);
}
