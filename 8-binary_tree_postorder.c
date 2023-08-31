#include "binary_trees.h"

/**
 * binary_tree_postorder - in-order traversal method
 * @tree: The tree to traverse in binary tree
 * @func: This pointer points to a function to call each node in tree
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func || !tree)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
