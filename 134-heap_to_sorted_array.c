#include "binary_trees.h"

/**
 * tree_size - This measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_size(tree->left);

	if (tree->right)
		height_right = 1 + tree_size(tree->right);

	return (height_left + height_right);
}

/**
 * heap_to_sorted_array - This converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int z, *ary = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	ary = malloc(sizeof(int) * (*size));

	if (!ary)
		return (NULL);

	for (z = 0; heap; z++)
		ary[z] = heap_extract(&heap);

	return (ary);
}
