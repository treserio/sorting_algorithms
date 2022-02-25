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
void merge_sort(int *array, size_t size);
void sp_merge(int *array, int *temp_arr, size_t low, size_t mid, size_t high);
void merge(int *array, int *temp_arr, size_t low, size_t mid, size_t high);
size_t mid_point(size_t size);
void p_array(int *array, size_t idx, size_t end);

/* heap sorting */
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t p_idx, size_t sz, size_t actual_size);
void heapify(int *array, int heap, int i, int size);

#endif
