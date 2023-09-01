#include "binary_trees.h"

/**
 * binary_tree_rotate_right - The Function that  rotates
 * right the binary tree...
 * @tree: The root node of the three BT
 * Return: Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivotTree;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pivotTree = tree->left;
	tree->left = pivotTree->right;
	if (pivotTree->right != NULL)
	{
		pivotTree->right->parent = tree;
	}
	pivotTree->right = tree;
	pivotTree->parent = tree->parent;
	tree->parent = pivotTree;
	return (pivotTree);
}
