#include "binary_trees.h"
avl_t *balance_tree(avl_t *tree, int value)
{
    int bf;
    bf = binary_tree_balance(tree);
    if (bf > 1 && value < tree->left->n)
    {
        return (binary_tree_rotate_right(tree));
    }
    else if (bf < -1 && value > tree->right->n)
    {
        return (binary_tree_rotate_left(tree));
    }
    else if (bf > 1 && value > tree->left->n)
    {
        tree->left = binary_tree_rotate_left(tree->left);
        return (binary_tree_rotate_right(tree));
    }
    else if (bf < -1 && value < tree->right->n)
    {
        tree->right = binary_tree_rotate_right(tree->right);
        return (binary_tree_rotate_right(tree));
    }
    return (tree);
}

avl_t *avl_insert(avl_t **tree, int value)
{
    bst_t *current, *new_node;
    if (tree)
    {
        current = *tree;
        if (*tree == NULL)
        {
            new_node = binary_tree_node(current, value);
            if (!new_node)
                return (NULL);
            *tree = new_node;
        }
        else if (current->n > value)
        {
            if (current->left)
                return (avl_insert(&current->left, value));
            new_node = binary_tree_node(current, value);
            if (!new_node)
                return (NULL);
            current->left = new_node;
        }
        else if (current->n < value)
        {
            if (current->right)
                return (avl_insert(&current->right, value));
            new_node = binary_tree_node(current, value);
            if (!new_node)
                return (NULL);
            current->right = new_node;
        }
        else
            return (NULL);

        return (balance_tree(new_node, value));
    }
    return (NULL);
}
