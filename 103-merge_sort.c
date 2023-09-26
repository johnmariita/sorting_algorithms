#include <stdio.h>
#include "sort.h"

/**
 * mergeSorted - function that merges two sub sorted arrays
 * @size: the size of the whole array
 * @a: the array
 * @l: the left most index
 * @mid: the middle point
 * @r: the right most index
 */
void mergeSorted(int size, int *a, int l, int mid, int r)
{
	int h = l, i = l, j = mid + 1, k, *b, c = 0;

	printf("Merging...\n[left]: ");
	for (k = l; k <= mid; k++)
	{
		if (c++ > 0)
			printf(", ");
		printf("%d", a[k]);
	}
	printf("\n[right]: ");
	for (k = mid + 1, c = 0; k <= r; k++)
	{
		if (c++ > 0)
			printf(", ");
		printf("%d", a[k]);
	}
	printf("\n");
	b = malloc(sizeof(int) * size);
	while ((h <= mid) && (j <= r))
		if (a[h] < a[j])
			b[i++] = a[h++];
		else
			b[i++] = a[j++];
	if (h > mid)
		for (k = j; k <= r; k++)
			b[i++] = a[k];
	else
		for (k = h; k <= mid; k++)
			b[i++] = a[k];
	for (k = l; k <= r; k++)
		a[k] = b[k];
	printf("[Done]: ");
	for (k = l, c = 0; k <= r; k++)
	{
		if (c++ > 0)
			printf(", ");
		printf("%d", a[k]);
	}
	printf("\n");
	free(b);
}

/**
 * merge - recursive function that splits an array to sub arrays
 * @size: the size of the whole array
 * @array: the whole array
 * @l: the left most index
 * @r: the right most index
 */
void merge(int size, int *array, int l, int r)
{
	int mid;

	if (l < r)
	{
		mid = (l + (r - 1)) / 2;
		merge(size, array, l, mid);
		merge(size, array, mid + 1, r);
		mergeSorted(size, array, l, mid, r);
	}
}

/**
 * merge_sort - function that calls the recursive function merge
 * @array: the array
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	merge(size, array, 0, size - 1);
}
