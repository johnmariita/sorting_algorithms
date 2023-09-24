#include "sort.h"

/**
 * swap - function that swaps two elements
 * @a: memory address of the 1st element
 * @b: memory address of the 2nd element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - function that partitions an array
 * @array: the array
 * @start: the first index of the array to be partitioned
 * @end: the last index of the portion of the array to be partitioned
 * @size: the size of the whole array
 * Return: returns the index of the pivot
 */
int partition(int *array, int start, int end, int size)
{
	int pivot, i, partition_index;

	pivot = array[end];
	partition_index = start;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[partition_index]);
			partition_index++;
		}
	}
	swap(&array[partition_index], &array[end]);
	print_array(array, size);
	return (partition_index);
}

/**
 * q_sort - recursive function that sorts an array
 * @array: the array
 * @start: the first index of the portion of the array
 * @end: the last index of the portion of the array
 * @size: the size of the whole array
 */
void q_sort(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int pi = partition(array, start, end, size);

		q_sort(array, start, pi - 1, size);
		q_sort(array, pi + 1, end, size);
	}
}
/**
 * quick_sort - function that calls the recursive sort function
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	q_sort(array, 0, size - 1, size);

}
