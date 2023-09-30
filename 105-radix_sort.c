#include <stdlib.h>
#include "sort.h"

/**
 * power - function to compute the exponent of a number
 * @base: the base
 * @exp: the exponent
 * Return: the return the power of base to exp
 */
int power(int base, int exp)
{
	if (exp <= 0)
		return (1);
	return (base * power(base, exp - 1));
}


/**
 * count - function to count the place value of the largest int
 * @array: the array
 * @n: the size of the array
 * Return: returns the number of digits
 */
int count(int *array, size_t n)
{
	int i = 1, max = array[0], digits = 0;

	for ( ; i < (int)n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max > 0)
	{
		max /= 10;
		digits++;
	}
	return (digits);
}

/**
 * radix_sort - function that sorts an array using the radix sort
 * @array: the array
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int digits, divisor = 1, **bucket, i = 0, j, k = 0, l, *bucket_count;
	int digit;

	if (size < 2)
		return;
	digit = count(array, size);
	bucket = malloc(sizeof(int *) * 10);
	bucket_count = malloc(sizeof(int) * 10);
	while (divisor < power(10, digit))
	{
		for (j = 0; j < 10; j++)
		{
			bucket[j] = malloc(sizeof(int) * size);
			bucket_count[j] = 0;
		}
		while (i < (int)size)
		{
			digits = (array[i] / divisor) % 10;
			bucket[digits][bucket_count[digits]++] = array[i];
			i++;
		}
		for (j = 0; j < 10; j++)
		{
			for (l = 0; l < bucket_count[j]; l++)
			{
				array[k] = bucket[j][l];
				k++;
			}
			free(bucket[j]);
		}
		i = 0, k = 0;
		divisor *= 10;
		print_array(array, size);
	}
	free(bucket);
	free(bucket_count);
}
