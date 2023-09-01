#include "binary_trees.h"

/**
 * binary_tree_is_complete - function that checks if a binary
 * tree is complete..
 * @tree: the pointer to root node of tree to check
 *
 * Return: 1 if the tree is complete
 *         else 0 if the tree is not complete and
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t sizeTree;

	if (!tree)
		return (0);
	sizeTree = binary_tree_size(tree);

	return (btic_helper(tree, 0, sizeTree));
}

/**
 * btic_helper1 - function checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         else 0 if the tree is not complete and
 *         0 if tree is NULL
 */
int btic_helper1(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper1(tree->left, 2 * index + 1, size) &&
		btic_helper1(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - function measures the size of a binary tree
 * @tree: the tree to measure the size of BT
 *
 * Return: size of the tree
 *         else 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
