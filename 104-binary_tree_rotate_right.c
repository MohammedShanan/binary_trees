#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *parent, *l_child;
if (!tree || !tree->left)
{
return (NULL);
}
l_child = tree->left;
parent = tree;
if (parent->parent)
{
if (parent->parent->left == parent)
{
parent->parent->left = l_child;
}
else
{
parent->parent->right = l_child;
}
}
l_child->parent = parent->parent;
parent->parent = l_child;
parent->left = l_child->right;
if (l_child->right)
{
l_child->right->parent = parent;
}
l_child->right = parent;
return (l_child);
}
