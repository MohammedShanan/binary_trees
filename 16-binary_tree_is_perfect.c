#include "binary_trees.h"
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

/**
 * get_depth - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * Return: depth of leftmost leaf
 */

int get_depth(const binary_tree_t *tree)
{
if (tree)
{
return (1 + get_depth(tree->left));
}
return (0);
}

/**
 * is_perfect - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: If the tree is perfect, 1, otherwise
 */

int is_perfect(const binary_tree_t *tree, int depth, int level)
{
if (binary_tree_is_leaf(tree))
{
return (depth == level + 1 ? 1 : 0);
}
if (tree->left == NULL || tree->right == NULL)
{
return (0);
}
level++;
return (is_perfect(tree->left, depth, level) &&
is_perfect(tree->right, depth, level));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or not perfect, 0.
 * Otherwise, 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}
return (is_perfect(tree, get_depth(tree), 0));
}
