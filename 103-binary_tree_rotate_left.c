#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  a left rotation
 * @tree: Pointerroot
 *
 * Return: Pointer
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *angl, *parent = tree;

	if (!tree)
		return (NULL);

	angl = parent->right;
	if (!angl)
		return (tree);

	if (angl->left)
		angl->left->parent = parent;

	parent->right = angl->left;
	angl->left = parent;
	angl->parent = parent->parent;
	parent->parent = angl;

	if (angl->parent && angl->parent->left == parent)
		angl->parent->left = angl;
	else if (angl->parent)
		angl->parent->right = angl;

	return (angl);
}
