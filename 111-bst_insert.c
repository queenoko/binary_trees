#include "binary_trees.h"

/**
 * bst_insert - this will inserts a value in a Binary Search Tree
 * @tree: the double pointer to root node of BST to insert value
 * @value: value to store in the node to be inserted
 * Return: A pointer to the created node
 *         else NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *second_value = NULL;
	bst_t *new_value = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		second_value = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new_value = binary_tree_node(NULL, value);
	if (second_value == NULL)
		second_value = new_value;
	else if (value < second_value->n)
	{
		second_value->left = new_value;
		new_value->parent = second_value;
	}
	else
	{
		second_value->right = new_value;
		new_value->parent = second_value;
	}

	return (new_value);
}
