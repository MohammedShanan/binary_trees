#include "binary_trees.h"
/**
 * array_to_heap - Builds a max heap from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 * Return: A pointer to the root node of the created heap, or NULL upon failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
heap_t *root = NULL;
size_t i;
if (array == NULL)
{
return (NULL);
}
for (i = 0; i < size; i++)
{
heap_insert(&root, array[i]);
}
return (root);
}
