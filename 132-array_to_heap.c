#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int z;
	heap_t *root_heap = NULL;

	for (z = 0; z < size; z++)
		heap_insert(&root_heap, array[z]);

	return (root_heap);
}
