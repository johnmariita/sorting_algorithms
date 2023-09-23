#include "sort.h"

/**
 * selection_sort - funtion that sorts an array using
 * the quick sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, pos;
	int small;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		small = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < small)
			{
				small = array[j];
				pos = j;
			}
		}
		array[pos] = array[i];
		array[i] = small;
		print_array(array, size);
	}
}
