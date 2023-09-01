#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds lowest
 * common ancestor of two nodes
 * @first: pointer to the first node to find the ancestor..
 * @second: pointer to the second node to find the ancestor..
 *
 * Return: pointer to the ancestor node
 *         else NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_fst, depth_snd;

	if (!first || !second)
		return (NULL);

	depth_fst = binary_tree_depth(first);
	depth_snd = binary_tree_depth(second);

	while (depth_fst > depth_snd)
	{
		first = first->parent;
		depth_fst--;
	}
	while (depth_snd > depth_fst)
	{
		second = second->parent;
		depth_snd--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - This measures the depth of node in binary tree
 * @tree: The node to calculate the depth of BT
 *
 * Return: depth of the node
 *         else 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dept = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		dept++;
		tree = tree->parent;
	}

	return (dept);
}
