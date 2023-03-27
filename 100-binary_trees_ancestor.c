#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
            const binary_tree_t *second)
{
binary_tree_t *first_anc, *second_anc;
if (!first || !second)
{
return (NULL);
}
first_anc = first->parent;
second_anc = second->parent;
if (first == second_anc || !first_anc)
{
return ((binary_tree_t *)first);
}
else if (second == first_anc || !second_anc)
{
return ((binary_tree_t *)second);
}
else if (first_anc->parent == NULL)
{
return (first_anc);
}
else if (second_anc->parent == NULL)
{
return (second_anc);
}
return (binary_trees_ancestor(first_anc, second_anc));
}
