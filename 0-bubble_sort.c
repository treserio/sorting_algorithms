#include "sort.h"

/**
 * bubble_sort - sort the array, bubbeley
 * @array: pointer array to sort
 * @size: size of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap;

	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size - j - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
