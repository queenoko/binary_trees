#include "binary_trees.h"

/**
 * binary_tree_height_b - This Measures height of a binary tree for
 * balance tree
 * @tree: This tree to go through bal
 * Return: the height BT
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left_node = 0;
	size_t right_node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left_node = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			right_node = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((left_node > right_node) ? left_node : right_node);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int rightNode = 0, leftNode = 0, totalN = 0;

	if (tree)
	{
		leftNode = ((int)binary_tree_height_b(tree->left));
		rightNode = ((int)binary_tree_height_b(tree->right));
		totalN = leftNode - rightNode;
	}
	return (totalN);
}
