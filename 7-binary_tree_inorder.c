#include "binary_trees.h"

/**
 * binary_tree_inorder - in-order traversal method
 * @tree: The tree to traverse in binary tree
 * @func: This pointer points to a function to call each node in tree
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func || !tree)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
