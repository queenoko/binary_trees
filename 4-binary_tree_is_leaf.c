#include "binary_trees.h"

/**
 * binary_tree_is_leaf - This checks if node is leaf
 * in binary tree
 * @node: check node of binary tree
 *
 * Return: 1 if node is leaf
 *         0 if not a leaf
 *         0 if node is NULL...
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->right || node->left) ? 0 : 1);
}
