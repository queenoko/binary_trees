#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes
 * with at least 1 child in a binary tree...
 * @tree: The tree to count the nodes with at least one child
 *
 * Return: The number of nodes counted
 *         else 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if ((!tree->right && !tree->left) || !tree)
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

/**
 * binary_tree_size - This measures the size of BT
 * @tree: This tree measures the size of BT
 *
 * Return: The size of the tree
 *         else 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree..
 * @tree: The tree to count the leaves from BT
 *
 * Return: The number of leaves
 *         else 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}
