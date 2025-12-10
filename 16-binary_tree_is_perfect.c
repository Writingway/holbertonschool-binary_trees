#include "binary_trees.h"

/**
* binary_tree_height - Calculates the height of a binary tree
* @tree: Pointer to the root node of the tree
*
* Return: Height of the tree, or 0 if tree is NULL
*/
static size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
* binary_tree_size - Counts the number of nodes in a binary tree
* @tree: Pointer to the root node of the tree
*
* Return: Number of nodes in the tree, or 0 if tree is NULL
*/
static size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node
*
* Return: 1 if perfect, 0 otherwise.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	/* A perfect tree has size = 2^height - 1 */
	return (size == (size_t)((1 << height) - 1) ? 1 : 0);
}
