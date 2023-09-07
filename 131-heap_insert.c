#include "binary_trees.h"

/**
 * heap_insert - This function inserts a
 * value in Max Binary Heap
 * @root: a double pointer to the root node of the
 * Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree1, *newHeap, *flip1;
	int size, leaves, sub, bit, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree1 = *root;
	size = binary_tree_size(tree1);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree1 = leaves & bit ? tree1->right : tree1->left;

	newHeap = binary_tree_node(tree1, value);
	leaves & 1 ? (tree1->right = newHeap) : (tree1->left = newHeap);

	flip1 = newHeap;
	for (; flip1->parent && (flip1->n > flip1->parent->n); flip1 = flip1->parent)
	{
		temp = flip1->n;
		flip1->n = flip1->parent->n;
		flip1->parent->n = temp;
		newHeap = newHeap->parent;
	}

	return (newHeap);
}

/**
 * binary_tree_size - Function measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
