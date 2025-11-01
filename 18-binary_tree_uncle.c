#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle for
 *
 * Return: pointer to the uncle node, or NULL if none exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	/* check if node is NULL or has no parent */
	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	/* if there is no grandparent, there is no uncle */
	if (!grandparent)
		return (NULL);

	/* check if parent is left child or right child of grandparent */
	if (grandparent->left && grandparent->left != parent)
		return (grandparent->left);

	if (grandparent->right && grandparent->right != parent)
		return (grandparent->right);

	return (NULL);
}
