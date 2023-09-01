#include "binary_trees.h"

/**
 * bst_search - This searches for a value in
 * a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing an int equal to `value`
 *         else NULL if tree is NULL
 *         and NULL if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node_val = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node_val)
	{
		if (value == node_val->n)
			return (node_val);
		if (value < node_val->n)
			node_val = node_val->left;
		else if (value > node_val->n)
			node_val = node_val->right;
	}

	return (NULL);
}
