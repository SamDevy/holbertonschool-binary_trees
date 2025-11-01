#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root of the BST
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure or duplicate
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *parent, *new_node;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	parent = NULL;

	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL); /* Duplicate value, do not insert */
	}

	/* Allocate new node */
	new_node = binary_tree_node(parent, value);
	if (!new_node) /* malloc failed */
		return (NULL);

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
