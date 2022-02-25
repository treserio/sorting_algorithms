#include "sort.h"

/**
* bubble_sort - sort the array, bubbeley
* @array: pointer array to sort
* @size: size of elements in array
*/
void merge_sort(int *array, size_t size)
{
	// size_t r_mid;
	int *temp_arr = NULL;
	/* confirm we have an array, and size is over 1 */
	if (!array || size < 2)
		return;

	temp_arr = malloc(sizeof(int) * size);
	if (!temp_arr)
		return;

	/* split and merge, when merging values - 1 for index */
	sp_merge(array, temp_arr, 1, mid_point(1, size + 1), size);
	merge(array, temp_arr, 0, mid_point(1, size + 1)-1, size - 1);
	free(temp_arr);
}

void sp_merge(int *array, int *temp_arr, size_t low, size_t mid, size_t high)
{
	size_t l_mid, r_mid;
	/* find accurate l_mid point between low & mid */
	l_mid = low + mid_point(low, mid);
	if ((l_mid - low) + l_mid >= mid)
		--l_mid;
	/* check if we can go deeper left */
	/* left: low, l_mid, mid */
	printf("split-merge l:%ld, m:%ld, h:%ld, l_mid:%ld\n", low, mid, high, l_mid);
	if (mid - low > 3)
	{
		printf("call left split\n");
		sp_merge(array, temp_arr, low, l_mid, mid);
	}
	/* merge left */
	if (low <= l_mid)
		merge(array, temp_arr, low-1, l_mid-1, mid-1);
	else
		merge(array, temp_arr, low-1, low-1, mid-1);
	/* find accurate r_mid point between mid & high */
	r_mid = mid + mid_point(mid, high);
	if ((r_mid - mid) + r_mid > high)
		--r_mid;
	/* check if we can go deeper right */
	/* right: mid+1, r_mid, high */
	printf("RIGHT   mid:%ld r_mid:%ld high:%ld\n", mid, r_mid, high);
	if (high - mid > 3)
	{
		printf("call right split\n");
		sp_merge(array, temp_arr, mid+1, r_mid, high);
	}
	/* merge right */
	merge(array, temp_arr, mid, r_mid-1, high-1);
}

void merge(int *array, int *temp_arr, size_t low, size_t mid, size_t high)
{
	size_t temp, i, l, left, r, right;

	printf("Merging...\n");
	printf("low:%ld mid:%ld high:%ld\n", low, mid, high);
	for (i = low; i <= high; ++i)
		temp_arr[i] = array[i];
	if (high - low == 2)
	{
		printf("[left]: %d\n", temp_arr[low+1]);
		printf("[right]: %d\n", temp_arr[high]);
		if (temp_arr[low+1] > array[high])
		{
			temp = temp_arr[low+1];
			temp_arr[low+1] = temp_arr[high];
			temp_arr[high] = temp;
		}
		printf("[Done]: %d, %d\n", temp_arr[low+1], temp_arr[high]);
		printf("Merging...\n");
		printf("[left]: %d\n", array[low]);
		printf("[right]: %d, %d\n", temp_arr[low+1], temp_arr[high]);
		for (i = low, r = low + 1, left = 1, right = 2; i <= high; ++i)
		{
			if (left && temp_arr[low] < temp_arr[r])
				array[i] = temp_arr[low], --left;
			else if (right)
				array[i] = temp_arr[r], ++r, --right;
			else
				array[i] = temp_arr[low];
		}
		printf("[Done]: ");
		p_array(array, low, high);
		return;
	}
	printf("[left]: ");
	p_array(temp_arr, low, mid);
	printf("[right]: ");
	p_array(temp_arr, mid+1, high);
	left = mid - low + 1;
	right = high - mid;
	l = low;
	r = mid+1;
	i = low;
	printf("left: %ld, right: %ld\n", left, right);
	while (left && right)
	{
		if (temp_arr[l] < temp_arr[r])
			array[i++] = temp_arr[l++], --left;
		else
			array[i++] = temp_arr[r++], --right;
	}
	while (left)
		array[i++] = temp_arr[l++], --left;
	while (right)
		array[i++] = temp_arr[r++], --right;
	printf("[Done:] ");
	p_array(array, low, high);
}

size_t mid_point(size_t low, size_t high)
{
	size_t mid;

	if (!((high - low) % 2))
		mid = (high - low) / 2;
	else
		mid = ((high - low) - 1) / 2;
	return mid;
}

void p_array(int *array, size_t idx, size_t end)
{
	for (; idx < end; ++idx)
	{
		printf("%d", array[idx]);
		printf(", ");
	}
	printf("%d\n", array[idx]);
}
