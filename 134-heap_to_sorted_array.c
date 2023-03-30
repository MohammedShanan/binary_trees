#include "binary_trees.h"
/**
 * heap_to_sorted_array - create a sorted array from a max heap.
 * @heap: A pointer to the root node of the heap.
 * @size: size of the array.
 * Return: The size of the tree.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int *array;
size_t i;
if (heap == NULL)
{
    *size = 0;
    return (NULL);
}
*size = _binary_tree_size(heap);
array = malloc(sizeof(int) * (*size));
if (!array)
{
    *size = 0;
    return (NULL);
}

for (i = (*size); i >= 1; i--)
{
array[i - 1] = heap_extract(&heap);
}
return (array);
}
