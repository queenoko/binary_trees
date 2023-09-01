#include "binary_trees.h"

/**
 * array_to_bst - This builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the
 * array to be converted
 * @size: the number of elements in the array
 * Return: A pointer to the root node of the created BST
 *         else NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int z;
	bst_t *root_ele = NULL;

	for (z = 0; z < size; z++)
		bst_insert(&root_ele, array[z]);

	return (root_ele);
}
