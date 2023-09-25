#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool swapped;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
	{
	swapped = false;

	for (j = 0; j < size - i - 1; j++)
	{
	    if (array[j] > array[j + 1])
	    {
		/* Swap elements */
		temp = array[j];
		array[j] = array[j + 1];
		array[j + 1] = temp;

		/* Print the array after the swap */
		print_array(array, size);

		swapped = true;
	    }
	}

	/* If no swaps were made in this pass, the array is already sorted */
	if (!swapped)
	    break;
	}
}
