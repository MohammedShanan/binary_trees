#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *r_child, *parent;
if (!tree || !tree->right)
{
return (NULL);
}
parent = tree;
r_child = tree->right;
r_child->parent = parent->parent;
if (parent->parent)
{
if (parent->parent->left == parent)
{
parent->parent->left = r_child;
}
else
{
parent->parent->right = r_child;
}
}
parent->parent = r_child;
if (r_child->left)
{
r_child->left->parent = parent;
}
parent->right = r_child->left;
r_child->left = parent;
return (r_child);
}
