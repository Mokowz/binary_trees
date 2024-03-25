#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: If tree is NULL, must return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: if the tree is NULL, must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_side = 0, right_side = 0;

	if (tree)
	{
		left_side = (tree->left) ? 1 + binary_tree_height(tree->left) : 1;

		right_side = (tree->right) ? 1 + binary_tree_height(tree->right) : 1;
		return (left_side > right_side ? left_side : right_side);
	}
	return (0);
}