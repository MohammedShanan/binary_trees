#include "binary_trees.h"
/**
 * get_min - Get the node with the minimum value.
 * @root: A pointer to the root node of the BST to remove a node from.
 * Return: A pointer to the node with the minimum value.
 */
bst_t *get_min(bst_t *root)
{
while (root->left)
{
root = root->left;
}
return (root);
}
/**
 * delete_node - Removes a node from a binary search tree.
 * @node: A pointer to the root node of the BST to remove a node from.
 * Return: A pointer to the new root node after deletion.
 */
bst_t *delete_node(bst_t *node)
{
bst_t *tmp, *succ, *parent = node->parent;
tmp = node->left ? node->left : node->right;
if (node->left == NULL || node->right == NULL)
{
if (tmp)
tmp->parent = parent;
free(node);
return (tmp);
}
succ = get_min(node->right);
node->n = succ->n;
node->right = bst_remove(node->right, succ->n);
return (node);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 * Return: A pointer to the new root node after deletion.
 */

bst_t *bst_remove(bst_t *root, int value)
{
if (root)
{
if (root->n == value)
{
return (delete_node(root));
}
if (root->n > value)
{
root->left = bst_remove(root->left, value);
return (root);
}
root->right = bst_remove(root->right, value);
return (root);
}
return (NULL);
}
