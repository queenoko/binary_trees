#include "binary_trees.h"

/**
 * tree_height - This measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_height(tree->left);

	if (tree->right)
		height_right = 1 + tree_height(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);
}
/**
 * tree_size_h - This measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_right = 1 + tree_size_h(tree->right);

	return (height_left + height_right);
}

/**
 * _preorder - This goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - This heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tempRoot1, *tmp2;

	if (!root)
		return;

	tempRoot1 = root;

	while (1)
	{
		if (!tempRoot1->left)
			break;
		if (!tempRoot1->right)
			tmp2 = tempRoot1->left;
		else
		{
			if (tempRoot1->left->n > tempRoot1->right->n)
				tmp2 = tempRoot1->left;
			else
				tmp2 = tempRoot1->right;
		}
		if (tempRoot1->n > tmp2->n)
			break;
		value = tempRoot1->n;
		tempRoot1->n = tmp2->n;
		tmp2->n = value;
		tempRoot1 = tmp2;
	}
}

/**
 * heap_extract - This extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_ri, *node;

	if (!root || !*root)
		return (0);
	heap_ri = *root;
	value = heap_ri->n;
	if (!heap_ri->left && !heap_ri->right)
	{
		*root = NULL;
		free(heap_ri);
		return (value);
	}

	_preorder(heap_ri, &node, tree_height(heap_ri));

	heap_ri->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_ri);
	*root = heap_ri;
	return (value);
}
