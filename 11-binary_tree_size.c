#include "binary_trees.h"

/**
 * binary_tree_size - This measures the size of binary tree
 * @tree: The tree to measure the size of binary tree
 *
 * Return: The size of the tree
 *         else 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((binary_tree_size(tree->right) + 1)
		    + binary_tree_size(tree->left));
}
