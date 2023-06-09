#include "binary_trees.h"
/**
 * _binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 * Return: The size of the tree.
 */
size_t _binary_tree_size(const binary_tree_t *tree)
{
size_t size = 0;
if (tree)
{
size++;
size += _binary_tree_size(tree->left);
size += _binary_tree_size(tree->right);
}
return (size);
}

/**
 * _swap- swap two integers.
 * @a: pointer to the first value.
 * @b: pointer to the second value.
 */
void _swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
/**
 * heapify - heapify a subtree .
 * @root: pointer to the root of the heap
 */
void heapify(heap_t *root)
{
if (root && (root->right || root->left))
{
if (root->left && root->left->n > root->n)
{
if (root->right == NULL || root->left->n > root->right->n)
{
_swap(&root->n, &root->left->n);
heapify(root->left);
}
else
{
_swap(&root->n, &root->right->n);
heapify(root->right);
}
}
else if (root->right && root->right->n > root->n)
{
_swap(&root->n, &root->right->n);
heapify(root->right);
}
}
}

/**
 * get_last_node - get the last node of the heap.
 * @root: pointer to the root of the heap
 * @indx: indx of the current node
 * @last_indx: indx of the last node
 * Return: the last node in the heap.
 */

heap_t *get_last_node(heap_t *root, size_t indx, size_t last_indx)
{
heap_t *l_path, *r_path;
if (indx == last_indx)
{
return (root);
}
if (root)
{
l_path = get_last_node(root->left, 2 * indx + 1, last_indx);
r_path = get_last_node(root->right, 2 * indx + 2, last_indx);
if (l_path)
{
if (root->left == l_path)
{
root->left = NULL;
}
return (l_path);
}
else if (r_path)
{
if (root->right == r_path)
{
root->right = NULL;
}
return (r_path);
}
}
return (NULL);
}
/**
 * heap_extract - extracts the root node of a Max Binary Heap.
 * @root: a double pointer to the root of the heap
 * Return: the root node number or 0.
 */
int heap_extract(heap_t **root)
{
heap_t *last_node;
size_t last_node_indx;
int max_num;
if (*root == NULL)
{
return (0);
}
max_num = (*root)->n;
last_node_indx = _binary_tree_size(*root) - 1;
last_node = get_last_node(*root, 0, last_node_indx);
if (last_node == *root)
{
free(*root);
*root = NULL;
}
else
{
(*root)->n = last_node->n;
free(last_node);
heapify(*root);
}
return (max_num);
}
