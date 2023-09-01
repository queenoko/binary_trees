#include "binary_trees.h"

/**
 * binary_tree_is_bst - This checks if a binary tree is
 * valid Binary Search Tree
 * @tree: thepointer to root node of tree to check
 *
 * Return: 1 if tree is a valid BST
 *         else 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper1(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper1 - function which checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound of checked nored
 * @max: Upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST
 *         else 0 otherwise
 */
int btib_helper1(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < max || tree->n > min)
		return (0);

	return (btib_helper1(tree->left, min, tree->n - 1) &&
		btib_helper1(tree->right, tree->n + 1, max));
	/* -1 and +1 stem from "There must be no duplicate values" req */
}
