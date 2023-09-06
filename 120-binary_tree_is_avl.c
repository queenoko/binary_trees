#include "binary_trees.h"

/**
 * binary_tree_is_avl - This finds if a binary tree is avl
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is avl
 *         else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper1(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper1 - helper that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int btia_helper1(const binary_tree_t *tree, int min, int max)
{
	int path_len, path_ri;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_len = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_ri = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_len - path_ri) > 1)
		return (0);

	return (btia_helper1(tree->left, min, tree->n - 1) &&
		btia_helper1(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - This measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_len = 0;
	size_t height_ri = 0;

	if (!tree)
		return (0);

	height_len = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_ri = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_len > height_ri ? height_len : height_ri);
}
