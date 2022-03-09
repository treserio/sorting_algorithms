#include "sort.h"
/**
 * quick_sort - sort array of ints uring quick_sort Lomuto method
 * @array: an array of ints to sort
 * @size: the number of ints in the array
*/
void quick_sort(int *array, size_t size)
{
	q_sort(array, size, 0, size);
}

void q_sort(int *array, size_t size, size_t start, size_t end)
{
	size_t piv = start, i = end - 1;
	int swap;

	while (piv != i)
	{
		if (piv < i)
		{
			if (array[piv] > array[i])
			{
				swap = array[piv];
				array[piv] = array[i];
				array[i] = swap;
				swap = piv, piv = i, i = swap, ++i;
				print_array(array, size);
				continue;
			}
			--i;
		}
		else
		{
			if (array[piv] < array[i])
			{
				swap = array[piv];
				array[piv] = array[i];
				array[i] = swap;
				swap = piv, piv = i, i = swap, --i;
				print_array(array, size);
				continue;
			}
			++i;
		}
	}
	if (piv != start)
	{
		q_sort(array, size, start, piv);
		q_sort(array, size, piv + 1, size);
	}
}
