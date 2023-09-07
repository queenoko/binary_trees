#include "binary_trees.h"

/**
 * sorted_array_to_avl - This builds an AVL tree from an array...
 * @array: a pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *treeSort = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	treeSort = binary_tree_node(NULL, array[middle]);

	sata_helper1(&treeSort, array, -1, middle);
	sata_helper1(&treeSort, array, middle, size);

	return (treeSort);
}

/**
 * sata_helper1 - The helper function  that builds
 * an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: a pointer to the first element of the array to be converted
 * @lo: lower bound index
 * @hi: upper bound index
 */
void sata_helper1(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *newSort = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		newSort = binary_tree_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = newSort;
		else if (array[middle] < (*root)->n)
			(*root)->left = newSort;
		sata_helper1(&newSort, array, lo, middle);
		sata_helper1(&newSort, array, middle, hi);
	}
}
