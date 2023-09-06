#include "binary_trees.h"

/**
 * array_to_avl - This builds an AVL tree from array....
 * @array: array to create
 * @size: size of the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int z;
	avl_t *rootArray = NULL;

	for (z = 0; z < size; z++)
		avl_insert(&rootArray, array[z]);

	return (rootArray);
}
