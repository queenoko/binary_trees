#include "binary_trees.h"

/**
 * binary_tree_levelorder - function to traverst a binary tree
 * using level-order traverse
 * @tree: the tree to traverse in BT
 * @func: pointer to a function to call for each node in BT
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t node_level, node_maxlevel;

	if (!tree || !func)
		return;

	node_maxlevel = binary_tree_height(tree) + 1;

	for (node_level = 1; node_level <= node_maxlevel; node_level++)
		btlo_helper1(tree, func, node_level);
}

/**
 * btlo_helper1 - function taht goes through a binary
 * tree using post-order traverse
 * @tree: the tree to traverse
 * @func: the pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void btlo_helper1(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper1(tree->left, func, level - 1);
		btlo_helper1(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: the tree to measure the height of
 *
 * Return: height of the tree
 *         else 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}
