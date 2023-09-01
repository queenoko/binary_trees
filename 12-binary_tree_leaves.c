#include "binary_trees.h"

/**
 * binary_tree_leaves - This function counts the leaves in a binary tree
 * @tree: This is the tree that counts the leaves
 *
 * Return: number of leaves
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
