#include "sort.h"

/**
 * radix_sort - sort using a radix algorithm
 * @array: the array that we've heaped
 * @size: the size of array
 */

void radix_sort(int *array, size_t size)
{
	size_t places, base, digit, div, i, j, total = 0;
	int *swap_arr;
	/* no need to sort cases */
	if (!array || size < 2)
		return;
	/* malloc swap_arr for place holders */
	swap_arr = malloc(sizeof(int) * size);
	if (!swap_arr)
		return;
	/* find the most significant digits in the array */
	for (i = 0; i < size; ++i)
	{
		for (base = 1, places = 0; array[i] / base; base *= 10)
			++places;
		if (places > total)
			total = places;
	}
	/* sort based on significant digits, for each sig digit */
	for (div = 1; total; --total, div *= 10)
	{
		/* copy the current state of the array to our swap array */
		for (i = 0; i < size; ++i)
			swap_arr[i] = array[i];
		/* sort based on current values from 0 to base*/
		for (digit = 0, j = 0; digit * div < base * div && j < size; ++digit)
			/* compare each value to the current digit */
			for (i = 0; i < size; ++i)
				if ((swap_arr[i] % (div * base)) / div == digit)
					array[j++] = swap_arr[i];
		print_array(array, size);
	}
}
