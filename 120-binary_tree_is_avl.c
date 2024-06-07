#include "binary_trees.h"

/**
 * btl - auxiliary level
 *
 * @tree: pointer to root
 * Return: integer with level
 */
int btl(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	height_left = btl(tree->left);
	height_right = btl(tree->right);
	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * bt_balance - factor calculate
 *
 * @tree: pointer to root
 * Return: integer with factor
 */
int bt_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btl(tree->left) - btl(tree->right));
}

/**
 * bavl - Check level
 *
 * @tree: pointer to root
 * @min: min value
 * @max: max value
 * Return: 1 if is AVL, 0 otherwise
 */
int bavl(const binary_tree_t *tree, int min, int max)
{
	int balance_left, balance_right, balance;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	balance = bt_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	balance_left = bavl(tree->left, min, tree->n - 1);
	balance_right = bavl(tree->right, tree->n + 1, max);
	if (balance_left == 1 && balance_right == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bavl(tree, INT_MIN, INT_MAX));
}
