#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursively sorts an array of integers using
 *                       the Quick sort algorithm.
 * @array: The array to be sorted.
 * @low: The lowest index of the current partition.
 * @high: The highest index of the current partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
	ssize_t pivot = lomuto_partition(array, low, high, size);

	quick_sort_recursive(array, low, pivot - 1, size);
	quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: The lowest index of the current partition.
 * @high: The highest index of the current partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; j++)
	{
	if (array[j] < pivot)
	{
	    i++;
	    if (i != j)
	    {
		swap_ints(array + i, array + j);
		print_array(array, size);
	    }
	}
	}

	if (array[i + 1] != array[high])
	{
	swap_ints(array + i + 1, array + high);
	print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
