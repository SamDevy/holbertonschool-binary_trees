#include "binary_trees.h"

/**
 * bst_find_parent - Finds the parent node for insertion
 * @root: Root of BST
 * @value: Value to insert
 * Return: Pointer to parent node or NULL if value exists
 */
bst_t *bst_find_parent(bst_t *root, int value)
{
	while (root)
	{
		if (value < root->n)
		{
			if (!root->left)
				return (root);
			root = root->left;
		}
		else if (value > root->n)
		{
			if (!root->right)
				return (root);
			root = root->right;
		}
		else
			return (NULL);
	}
	return (NULL);
}

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to root node
 * @value: Value to insert
 * Return: Pointer to created node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent, *node;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		node = binary_tree_node(NULL, value);
		if (!node)
			return (NULL);
		*tree = node;
		return (node);
	}

	parent = bst_find_parent(*tree, value);
	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;

	return (node);
}
