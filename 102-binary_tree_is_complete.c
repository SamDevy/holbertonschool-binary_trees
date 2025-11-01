#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	size_t front = 0, back = 0, size = 0;
	int encountered_null = 0;

	if (tree == NULL)
		return (0);

	size = 1024;
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (queue == NULL)
		return (0);

	queue[back++] = tree;

	while (front < back)
	{
		const binary_tree_t *node = queue[front++];

		if (node == NULL)
		{
			encountered_null = 1;
			continue;
		}

		if (encountered_null)
		{
			free((void *)queue);
			return (0);
		}

		queue[back++] = node->left;
		queue[back++] = node->right;
	}

	free((void *)queue);
	return (1);
}
