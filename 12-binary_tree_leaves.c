#include "binary_trees.h"
/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 * Return: The number of leaves in the tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t leaves = 0;
if (binary_tree_is_leaf(tree))
{
return (1);
}
else if (tree)
{
leaves += binary_tree_leaves(tree->left);
leaves += binary_tree_leaves(tree->right);
}
return (leaves);
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 * Return: If the node is a leaf - 1.
 *Otherwise - 0.
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node == NULL || node->left != NULL || node->right != NULL)
{
return (0);
}
return (1);
}
