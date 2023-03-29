#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l, height_r;
    height_l = height_r = 0;
    if (tree)
    {
        height_l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
        height_r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
        return (height_l > height_r ? height_l : height_r);
    }
    return (0);
}
/**
 * is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl(const binary_tree_t *tree, int lo, int hi)
{
    size_t r_height, l_height;
    int diff;
    if (tree)
    {
        if (tree->n <= lo || tree->n >= hi)
        {
            return (0);
        }
        r_height = binary_tree_height(tree->left);
        l_height = binary_tree_height(tree->right);
        diff = r_height - l_height;
        if (diff > 1 || diff < -1)
        {
            return (0);
        }
        return (is_avl(tree->left, lo, tree->n) &&
                is_avl(tree->right, tree->n, hi));
    }
    return (1);
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }
    return (is_avl(tree, INT_MIN, INT_MAX));
}
