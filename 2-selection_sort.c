#include "sort.h"
/**
 * selection_sort - Sorts an array of ints in place
 * @array: an array of ints to sort
 * @size: the number of ints in the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, tiny;
	int swap;
	/* exit cases */
	if (!array || size < 2)
		return;

	for (i = 0; i < size; ++i)
	{
		tiny = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[tiny])
				tiny = j;
		}
		if (tiny != i)
		{
			swap = array[i];
			array[i] = array[tiny];
			array[tiny] = swap;
			p_array(array, 0, size);
		}
	}
}

/**
 * p_array - print the given array from idx to end
 * @array: pointer to the beginning of the array to print from
 * @idx: the starting index to print from
 * @end: the final index to print
*/
void p_array(int *array, size_t idx, size_t end)
{
	for (; idx < end - 1; ++idx)
	{
		printf("%d", array[idx]);
		printf(", ");
	}
	printf("%d\n", array[idx]);
}
