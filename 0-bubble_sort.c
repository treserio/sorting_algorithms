#include "sort.h"

/**
 * bubble_sort - sort the array, bubbeley
 * @array: pointer array to sort
 * @size: size of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	int swap, sz = 0;
	size_t i, j;

	for (j = 0; j < size - 1; j++, ++sz)
	{
		for (i = 0; i < size - 1; ++i, ++sz)
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
