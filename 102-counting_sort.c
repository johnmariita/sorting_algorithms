#include "sort.h"

/**
 * counting_sort - function that sorts an array using the counting sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int max;
	int *count, *sorted;

	if (size < 2)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i <= (unsigned int)max; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= (unsigned int)max; i++)
		count[i] += count[i - 1];
	print_array((const int *)count, max + 1);
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	for (i = size - 1; (int)i >= 0; i--)
	{
		sorted[--count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}
