#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  rotation on a tree
 * @tree: Pointer to
 *
 * Return: Pointer
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *angl, *parent = tree;

	if (!tree)
		return (NULL);

	angl = parent->left;
	if (!angl)
		return (tree);

	if (angl->right)
		angl->right->parent = parent;

	parent->left = angl->right;
	angl->right = parent;
	angl->parent = parent->parent;
	parent->parent = angl;

	if (angl->parent && angl->parent->left == parent)
		angl->parent->left = angl;
	else if (angl->parent)
		angl->parent->right = angl;

	return (angl);
}
