#include "binary_trees.h"
/**
 * free_queue - free the queue
 * @head: first node in the queue
 */
void free_queue(queue *head)
{
queue *tmp;
while (head)
{
tmp = head;
head = head->next;
free(tmp);
}
}

/**
 * enqueue - Insert a node into the queue
 * @node: A binary tree node
 * @head: First node in the queue
 * @tail: Last node in the queue
 */

void enqueue(const binary_tree_t *node, queue **head, queue **tail)
{
queue *new_node;
new_node = malloc(sizeof(queue));
if (new_node == NULL)
{
return;
}
new_node->node = node;
new_node->next = NULL;
if (*tail)
{
(*tail)->next = new_node;
}
if (*head == NULL)
{
*head = new_node;
}
*tail = new_node;
}

/**
 * dequeue - Return the first node in the a queue and moves queue by one node
 * @head: First node in the queue
 * Return: First node in the queue
 */

queue *dequeue(queue **head)
{
queue *tmp;
tmp = *head;
*head = tmp->next;
return (tmp);
}
/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
queue *head = NULL, *tail = NULL, *tmp;
const binary_tree_t *tmp_node = tree;
if (!tree || !func)
{
return;
}
enqueue(tree, &head, &tail);
tmp = head;
while (tmp)
{
tmp_node = dequeue(&tmp)->node;
func(tmp_node->n);
if (tmp_node->left)
{
enqueue(tmp_node->left, &tmp, &tail);
}
if (tmp_node->right)
{
enqueue(tmp_node->right, &tmp, &tail);
}
}
free_queue(head);
}
