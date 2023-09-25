#include "sort.h"

/**
 * swap - function that swaps two elements
 * @a: the ist element
 * @b: the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - function that sorts an array using the shell sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, gap;
	int j;

	if (size < 2)
		return;
	for (gap = 1; gap < size / 3;)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap = gap / 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0; j = j - gap)
			{
				if (array[j + gap] > array[j])
					break;
				swap(&array[j + gap], &array[j]);
			}
		}
		print_array(array, size);
	}
}
