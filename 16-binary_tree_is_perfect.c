#include "binary_trees.h"

/**
 * binary_tree_is_perfect - function that checks if a binary tree i perfect
 * @tree: the pointer to root node of tree to check
 *
 * Return: 1 if the tree is perfect else
 *         0 if the tree is not perfect and
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t heightOftree = 0;
	size_t nodesOftree = 0;
	size_t powerOftree = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	heightOftree = binary_tree_height(tree);
	nodesOftree = binary_tree_size(tree);

	powerOftree = (size_t)_pow_recursion(2, heightOftree + 1);
	return (powerOftree - 1 == nodesOftree);
}

/**
 *_pow_recursion - function returns the value of m raised to the power of n
 *@m: the value to exponentiate
 *@n: the power to raise m to
 *Return: m to the power of n, or -1 if n is negative
 */

int _pow_recursion(int m, int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	else
		return (m * _pow_recursion(m, n - 1));

}

/**
 * binary_tree_size -function that measures the size of a binary tree
 * @tree: the tree to measure the size of
 *
 * Return: the size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - function that measures the height of binary tree
 * @tree:  this tree to measure the height  BT
 *
 * Return: the height of the tree
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
