#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *swap - Swap between two elements in an array
 *@a: first element
 *@b: second element
 */

void swap(int *a, int *b)

{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *heapify - a function that builds and sort a max heap tree
 *@array: unordered array of integers
 *@n: the actual length of the input array
 *@i: index
 *@size:length of the entire array
 */

void heapify(int *array,  size_t n, size_t i, size_t size)

{
	unsigned int largest = i;
	unsigned int l = 2 * i + 1;
	unsigned int r = 2 * i + 2;

	if (l < n && array[l] > array[largest])
	{
		largest = l;
	}

	if (r < n && array[r] > array[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

/**
 *heap_sort - a function that sorts an array of integers in ascending order
 *@array:the unsorted array of integers
 *@size: the length of the unsorted array
 */

void heap_sort(int *array, size_t size)

{
	unsigned int i;

	if (size < 2)
		return;

	for (i = size / 2 - 1; (int)i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; (int)i >= 0; i--)

	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);

	}

}
