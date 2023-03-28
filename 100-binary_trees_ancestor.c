#include "binary_trees.h"
/**
 * findLCA - Finds the lowest common ancestor of two nodes.
 * @root: Pointer root node.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *findLCA(binary_tree_t *root,
const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *left_lca, *right_lca;
if (root == NULL)
{
return (NULL);
}

if (root == first || root == second)
{
return (root);
}
left_lca = findLCA(root->left, first, second);
right_lca = findLCA(root->right, first, second);
if (left_lca && right_lca)
{
return (root);
}
return (left_lca ? left_lca : right_lca);
}
/**
 * get_root - Finds the root node.
 * @node: Pointer to a node to start search from.
 * Return: The root node.
 */

binary_tree_t *get_root(binary_tree_t *node)
{
if (node->parent == NULL)
{
return (node);
}
return (get_root(node->parent));
}
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{

if (!first || !second)
{
return (NULL);
}

return (findLCA(get_root((binary_tree_t *)first), first, second));
}
