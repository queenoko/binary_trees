#include "binary_trees.h"

/**
 * binary_tree_preorder - pre-order traversal method
 * @tree: The tree to traverse in binary tree
 * @func: This pointer points to a function to call each node in tree
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func || !tree)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
