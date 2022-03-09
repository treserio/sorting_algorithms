#include "sort.h"

/**
 * quick_sort - sorts an array from low to high.
 *
 * @array: the array.
 * @size: the size of the array.
 *
 */

void quick_sort(int *array, size_t size)
{ /* checks if array is valid */
	if (array != NULL)
	{ /* recursive low to highest */
		sort(array, 0, size - 1, size);
	}
}

/**
 * sort - using recursion to sort from low to high.
 *
 * @array: the array.
 * @low: the beginning of the sort.
 * @high: the end point of the sort.
 * @size: the size of the array.
 *
 * Return: void.
 */

void sort(int *array, int low, int high, size_t size)
{
	int pivotINDEX;
	/* checks for two values */
	if (low < high)
	{ /* find index of pivot */
		pivotINDEX = partition(array, low, high, size);
		/* quicksort to go both directions */
		sort(array, low, pivotINDEX - 1, size);
		sort(array, pivotINDEX + 1, high, size);
	}
}
/**
 * partition - finds the pivotINDEX of an array.
 *
 * @array: the array.
 * @low: the beginning of the sort.
 * @high: the end point of the sort.
 * @size: the size of the array.
 *
 * Return: our new pivot index.
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], pivotINDEX = low, i;
	/* move smallest # to left and greatest # to right */
	for (i = low; i < high; i++)
	{ /* checks if our index is larger than pivot */
		if (array[i] <= pivot)
		{ /* index in our array becomes our pivotINDEX */
			swapArray(array, i, pivotINDEX);
			/* print the array if our pivotINDEX does not equal array index */
			if (pivotINDEX != i)
			{
				print_array(array, size);
			}
			/* move right till we hit # greater than pivot */
			pivotINDEX++;
		}
	}
	/* swap pivotINDEX and high to find our high */
	swapArray(array, pivotINDEX, high);
	if (pivotINDEX != high)
	{
		print_array(array, size);
	}
	return (pivotINDEX);
}

/**
 * swapArray - swaps two elements in an array.
 *
 * @array: the array.
 * @first: the first element.
 * @second: the second element.
 *
 */

void swapArray(int *array, int first, int second)
{
	int tmp;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;
}
