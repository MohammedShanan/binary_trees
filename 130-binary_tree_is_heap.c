#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t size = 0;
if (tree)
{
size++;
size += binary_tree_size(tree->left);
size += binary_tree_size(tree->right);
}
return (size);
}
/**
 * is_max_heap - Checks if a binary tree is max heap.
 * @tree: A pointer to the root node of the tree to traverse.
 * @index: index of the current node been check.
 * @size: Number of nodes in the tree.
 * Return: If the tree is NULL or not complete, 0.
 * Otherwise, 1.
 */
int is_max_heap(const binary_tree_t *tree, size_t index, size_t size)
{
if (tree)
{
if ((tree->left && tree->left->n > tree->n) ||
(tree->right && tree->right->n > tree->n))
{
return (0);
}
if (index >= size)
{
return (0);
}
return (is_max_heap(tree->left, 2 * index + 1, size) &&
is_max_heap(tree->right, 2 * index + 2, size));
}
return (1);
}
/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}
return (is_max_heap(tree, 0, binary_tree_size(tree)));
}
