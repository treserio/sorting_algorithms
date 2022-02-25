#include "sort.h"

/**
* merge_sort - sort the array, mergey
* @array: pointer to array to sort
* @size: size of elements in array
*/
void merge_sort(int *array, size_t size)
{
	int *temp_arr = NULL;
	/* confirm we have an array, and size is over 1 */
	if (!array || size < 2)
		return;

	temp_arr = malloc(sizeof(int) * size);
	if (!temp_arr)
		return;

	/* check if size is 3 or smaller */
	if (size < 4)
		merge(array, temp_arr, 0, mid_point(1, size + 1) - 1, size - 1);
	else
	{
		/* split and merge, when merging values - 1 for index */
		sp_merge(array, temp_arr, 1, mid_point(1, size + 1), size);
		merge(array, temp_arr, 0, mid_point(1, size + 1) - 1, size - 1);
	}
	free(temp_arr);
}

/**
* sp_merge - split merge, the part that actually splits the array
* @array: pointer to array to sort
* @temp_arr: pointer to temporary array for merging
* @low: low index of array
* @mid: mid index of array
* @high: max index of array
*/
void sp_merge(int *array, int *temp_arr, size_t low, size_t mid, size_t high)
{
	size_t l_mid, r_mid;
	/* find accurate l_mid point between low & mid */
	l_mid = low + mid_point(low, mid);
	if ((l_mid - low) + l_mid >= mid)
		--l_mid;
	/* check if we can go deeper left */
	/* left: low, l_mid, mid */
	if (mid - low > 3)
		sp_merge(array, temp_arr, low, l_mid, mid);
	/* merge left */
	if (low <= l_mid)
		merge(array, temp_arr, low - 1, l_mid - 1, mid - 1);
	else
		merge(array, temp_arr, low - 1, low - 1, mid - 1);
	/* find accurate r_mid point between mid & high */
	r_mid = mid + mid_point(mid, high);
	if ((r_mid - mid) + r_mid > high)
		--r_mid;
	/* check if we can go deeper right */
	/* right: mid+1, r_mid, high */
	if (high - mid > 3)
		sp_merge(array, temp_arr, mid + 1, r_mid, high);
	/* merge right */
	merge(array, temp_arr, mid, r_mid - 1, high - 1);
}

/**
* merge - merging in sides of array
* @array: pointer to array to sort
* @t_a: pointer to temporary array for merging
* @low: low index of array
* @mid: mid index of array
* @hi: max index of array
*/
void merge(int *array, int *t_a, size_t low, size_t mid, size_t hi)
{
	size_t temp, i, l = low, left, r = mid + 1, right;

	printf("Merging...\n");
	for (i = low; i <= hi; ++i)
		t_a[i] = array[i];
	if (hi - low == 2)
	{
		printf("[left]: %d\n[right]: %d\n", t_a[low + 1], t_a[hi]);
		if (t_a[low + 1] > array[hi])
		{
			temp = t_a[low + 1];
			t_a[low + 1] = t_a[hi];
			t_a[hi] = temp;
		}
		printf("[Done]: %d, %d\nMerging...\n", t_a[low + 1], t_a[hi]);
		printf("[left]: %d\n[right]: %d, %d\n", array[low], t_a[low + 1], t_a[hi]);
		for (i = low, r = low + 1, left = 1, right = 2; i <= hi; ++i)
			if (left && t_a[low] < t_a[r])
				array[i] = t_a[low], --left;
			else if (right)
				array[i] = t_a[r], ++r, --right;
			else
				array[i] = t_a[low];
		printf("[Done]: "), p_array(array, low, hi);
		return;
	}
	printf("[left]: "), p_array(t_a, low, mid);
	printf("[right]: "), p_array(t_a, mid + 1, hi);
	for (left = mid - low + 1, right = hi - mid, i = low; left && right;)
		if (t_a[l] < t_a[r])
			array[i++] = t_a[l++], --left;
		else
			array[i++] = t_a[r++], --right;
	while (left)
		array[i++] = t_a[l++], --left;
	while (right)
		array[i++] = t_a[r++], --right;
	printf("[Done]: "), p_array(array, low, hi);
}

/**
* mid_point - find the mid point of an intiger, will round down for odd number
* @low: the low value to find a mid point between
* @high: the high value to find a mid point between
* Return: the mid point of the number
*/
size_t mid_point(size_t low, size_t high)
{
	size_t mid;

	if (!((high - low) % 2))
		mid = (high - low) / 2;
	else
		mid = ((high - low) - 1) / 2;
	return (mid);
}

/**
* p_array - print the given array from idx to end
* @array: pointer to the beginning of the array to print from
* @idx: the starting index to print from
* @end: the final index to print
*/
void p_array(int *array, size_t idx, size_t end)
{
	for (; idx < end; ++idx)
	{
		printf("%d", array[idx]);
		printf(", ");
	}
	printf("%d\n", array[idx]);
}
