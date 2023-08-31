#include "binary_trees.h"

/**
 * binary_tree_is_root - This confirms if node
 * is a root
 * @node: The node to check in binary tree
 *
 * Return: 1 if node is a root in tree
 *         0 if not a root in tree
 *         0 if node is NULL in tree
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((node->parent || !node) ? 0 : 1);
}
