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
		for (j = i + 1, tiny = i; j < size; ++j)
			if (array[j] < array[tiny])
				tiny = j;
		if (tiny != i)
		{
			swap = array[i];
			array[i] = array[tiny];
			array[tiny] = swap;
			print_array(array, size);
		}
	}
}
