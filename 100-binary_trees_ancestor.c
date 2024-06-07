#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowes
 * @first: Pointer
 * @second: Pointer
 *
 * Return: Pointer
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *first_anc, *second_anc;

	for (first_anc = first; first_anc; first_anc = first_anc->parent)
		for (second_anc = second; second_anc; second_anc = second_anc->parent)
			if (first_anc == second_anc)
				return ((binary_tree_t *)first_anc);
	return (NULL);
}
