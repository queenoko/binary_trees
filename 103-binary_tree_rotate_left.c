#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that rotates left the binary tree...
 * @tree: The root node of the three..
 * Return: the Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivotTree;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pivotTree = tree->right;
	tree->right = pivotTree->left;
	if (pivotTree->left != NULL)
	{
		pivotTree->left->parent = tree;
	}
	pivotTree->left = tree;
	pivotTree->parent = tree->parent;
	tree->parent = pivotTree;
	return (pivotTree);
}
