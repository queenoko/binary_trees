#include "binary_trees.h"

/**
 * binary_tree_insert_left -  This inserts node the left-child of anoda node
 *
 * @parent: This is pointer to the node to insert the left-child in
 * @value:  The value to store in the new node
 *
 * Description - when a parent already has left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_leftchild;

	if (!parent)
		return (NULL);

	new_leftchild = malloc(sizeof(binary_tree_t));
	if (!new_leftchild)
		return (NULL);

	new_leftchild->n = value;
	new_leftchild->parent = parent;
	new_leftchild->right = NULL;
	new_leftchild->left = parent->left;
	parent->left = new_leftchild;
	if (new_leftchild->left)
		new_leftchild->left->parent = new_leftchild;
	return (new_leftchild);
}
