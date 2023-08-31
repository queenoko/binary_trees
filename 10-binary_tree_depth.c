#include "binary_trees.h"

/**
 * binary_tree_depth - This function measures the depth of node in binary tree
 * @tree: This cslculates the depth of a binary tree
 *
 * Return: the depth of node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t tree_depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		tree_depth++;
		tree = tree->parent;
	}

	return (tree_depth);
}
