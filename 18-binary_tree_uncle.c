#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node
 *
 * Return: pointer to uncle node, or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* check if node, parent, or grandparent is NULL */
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	/* uncle is the sibling of the parent */
	return (binary_tree_sibling(node->parent));
}
