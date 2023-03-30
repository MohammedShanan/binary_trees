#include "binary_trees.h"
/**
 * _binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 */
binary_tree_t *_binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;
new_node = malloc(sizeof(binary_tree_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = value;
new_node->left = NULL;
new_node->right = NULL;
new_node->parent = parent;

return (new_node);
}

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
 * swap- swap two integers.
 * @a: pointer to the first value.
 * @b: pointer to the second value.
 */
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
/**
 * heap_insert- Inserts a value in a Max heap.
 * @root: A double pointer to the root node of the max heap to insert the value
 * @value: The value to store in the node to be inserted.
 * @indx: index of the current node been check.
 * @parent_idx: indx of the parent of the new node/
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *max_heap_insert(heap_t *root, int value, size_t indx,
size_t parent_idx)
{
heap_t *new_node, *l_path, *r_path;
if (root)
{
if (indx == parent_idx)
{
new_node = _binary_tree_node(root, value);
if (!new_node)
return (NULL);
if (root->left)
root->right = new_node;
else
root->left = new_node;
}
else
{
l_path = max_heap_insert(root->left, value,
2 * indx + 1, parent_idx);
r_path = max_heap_insert(root->right, value,
2 * indx + 2, parent_idx);
if (l_path)
new_node = l_path;
else if (r_path)
new_node = r_path;
else
return (NULL);
}
if (root->n < new_node->n)
{
swap(&root->n, &new_node->n);
return (root);
}
return (new_node);
}
return (NULL);
}

/**
 * heap_insert- Inserts a value in a Max heap.
 * @root: A double pointer to the root node of the max heap to insert the value
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node;
size_t parent_indx, size;
if (*root == NULL)
{
new_node = _binary_tree_node(NULL, value);
if (!new_node)
{
return (NULL);
}
*root = new_node;
return (new_node);
}
size = binary_tree_size(*root) + 1;
parent_indx = size / 2 - 1;
return (max_heap_insert(*root, value, 0, parent_indx));
}
