#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

/* quick sorting */
void quick_sort(int *array, size_t size);
void quick(int *array, size_t size, size_t left, size_t right);
void q_sort(int *array, size_t size, size_t start, size_t end);
void sort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swapArray(int *array, int first, int second);

/* merge sorting */
void merge_sort(int *array, size_t size);
void sp_merge(int *array, int *temp_arr, size_t low, size_t mid, size_t high);
void merge(int *array, int *temp_arr, size_t low, size_t mid, size_t high);
size_t mid_point(size_t low, size_t high);
void p_array(int *array, size_t idx, size_t end);

/* heap sorting */
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t p_idx, size_t sz, size_t actual_size);

/* radix sorting */
void radix_sort(int *array, size_t size);

#endif
