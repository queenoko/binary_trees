#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of node
 * @node: the pointer to node to find uncle node
 *
 * Return: the pointer to uncle node
 *         else NULL if node is NULL and
 *         NULL if the parent is NULL
 *         NULL if the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node->parent || !node)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: the pointer to node to find sibling
 *
 * Return: the pointer to sibling node
 *         else NULL if node is NULL
 *         NULL if the parent is NULL and
 *         NULL if the node has no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node->parent || !node)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
