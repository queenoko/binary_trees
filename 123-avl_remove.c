#include "binary_trees.h"

/**
 * bal - This Measures balance factor of a AVL...
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bival;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bival = binary_tree_balance((const binary_tree_t *)*tree);
	if (bival > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bival < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get the next successorthe min node in the right subtree
 * @node: tree to check
 * Return: whenmin value of this tree
 */
int successor(bst_t *node)
{
	int left11 = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left11 = successor(node->left);
		if (left11 == 0)
		{
			return (node->n);
		}
		return (left11);
	}

}
/**
 *remove_type - The function that removes a node depending of its children
 *@root: root node to remove
 *Return: 0 if it has no children or
 *other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value1 = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value1 = successor(root->right);
		root->n = new_value1;
		return (new_value1);
	}
}
/**
 * bst_remove - This removes a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed binary
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type1 = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type1 = remove_type(root);
		if (type1 != 0)
			bst_remove(root->right, type1);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - This function removes a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_av = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_av == NULL)
		return (NULL);
	bal(&root_av);
	return (root_av);
}
