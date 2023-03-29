#include "binary_trees.h"
typedef struct queue
{
    const binary_tree_t *node;
    struct queue *next;

} queue;
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

queue *dequeue(queue **head)
{
    queue *tmp;
    tmp = *head;
    *head = tmp->next;
    return (tmp);
}

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
