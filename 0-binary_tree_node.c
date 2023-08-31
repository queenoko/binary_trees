#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node..
 *
 * @parent: - This is pointer to parent node of the node to create
 * @value: - value to put in the new node
 * Return: pointer to the new node, or NULL if failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* declaration of the new node with its data type */
	binary_tree_t *my_newNode;

	/* allocate memory space for that node */
	my_newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (my_newNode == NULL)
	{
		return (NULL);
	}

	/* assign values to the properties of the node */
	my_newNode->parent = parent;
	my_newNode->n = value;
	my_newNode->left = NULL;
	my_newNode->right = NULL;

	/* return a pointer to the node */
	return (my_newNode);
}
