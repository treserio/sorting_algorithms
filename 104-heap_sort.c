#include "sort.h"

/**
 * sift_down - shift lower values down to form max heap
 * @array: the array that we've heaped
 * @p_idx: the current parent to test
 * @sz: for when size of heap is reduced, to set smaller max
 * @actual_size: the size of array
 */
void sift_down(int *array, size_t p_idx, size_t sz, size_t actual_size)
{
	size_t l_idx = 2 * p_idx + 1;
	size_t r_idx = 2 * p_idx + 2;
	size_t new_p = p_idx;
	int swap = 0;
	/* check if either child is greater than the parent and sift down if so */
	for (; l_idx < sz; l_idx = 2 * p_idx + 1, r_idx = 2 * p_idx + 2)
	{
		if (array[new_p] < array[l_idx])
			new_p = l_idx;
		if (r_idx < sz && array[new_p] < array[r_idx])
			new_p = r_idx;

		if (new_p == p_idx)
			break;

		swap = array[p_idx];
		array[p_idx] = array[new_p];
		array[new_p] = swap;
		p_idx = new_p;
		print_array(array, actual_size);
	}
}

/**
 * heap_sort - sorts array with heap sort
 * @array: the array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int parent, sz = size - 1, swapper;
	/* check for inputs */
	if (array == NULL || size < 2)
		return;
	/* sift down for last parent and up, swapping largest to root */
	for (parent = size / 2 - 1; parent >= 0; --parent)
		sift_down(array, parent, size, size);
	/* move greatest value, root aka index 0, to end of array and fix heap */
	for (; sz; --sz)
	{
		/* swap the last value with the greatest, aka root */
		swapper = array[0];
		array[0] = array[sz];
		array[sz] = swapper;
		/* print the full array per task */
		print_array(array, size);
		/* sift down on the new root */
		sift_down(array, 0, sz, size);
	}
}
