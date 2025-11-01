#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: Uses a queue (FIFO) to traverse the tree level by level.
 * If tree or func is NULL, the function does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	size_t front = 0, back = 0, size = 0;

	if (tree == NULL || func == NULL)
		return;

	/* Allocate a dynamic queue for BFS traversal */
	size = 1024; /* Safe default size for most trees */
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
