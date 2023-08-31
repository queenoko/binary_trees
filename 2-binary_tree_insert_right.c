#include "binary_trees.h"

/**
 * binary_tree_insert_right - This inserts a node as the
 *					right-child of another node in binary
 *
 * @parent: This pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 *
 * Description: when parent already has right-child, new node
 *				must take its place, and the old right-child must
 *				be set as the right-child of the new node.
 *
 * Return: a pointer to the created node, or
 *			NULL on failure or
 *			if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_rightchild;

	if (!parent)
		return (NULL);

	new_rightchild = malloc(sizeof(binary_tree_t));
	if (!new_rightchild)
		return (NULL);

	new_rightchild->n = value;
	new_rightchild->parent = parent;
	new_rightchild->left = NULL;
	new_rightchild->right = parent->right;
	parent->right = new_rightchild;
	if (new_rightchild->right)
		new_rightchild->right->parent = new_rightchild;
	return (new_rightchild);
}
