#include "binary_trees.h"

/**
 * binary_tree_delete - This deletes the whole binary tree
 * @tree: This is the pointer to root node of tree to delete
 * Description: If tree is NULL, dont do anything
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
