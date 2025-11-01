#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a BST
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL if value exists or malloc fails
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *tmp;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		node = binary_tree_node(NULL, value);
		if (!node)
			return (NULL);
		*tree = node;
		return (node);
	}

	tmp = *tree;
	while (tmp)
	{
		if (value < tmp->n)
		{
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				node = binary_tree_node(tmp, value);
				if (!node)
					return (NULL);
				tmp->left = node;
				return (node);
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				node = binary_tree_node(tmp, value);
				if (!node)
					return (NULL);
				tmp->right = node;
				return (node);
			}
		}
		else
			return (NULL); /* Value already exists */
	}

	return (NULL);
}
