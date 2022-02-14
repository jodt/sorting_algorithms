#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define TRUE 1
#define FALSE 0

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

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(listint_t **list, listint_t *node1, listint_t *node2);
void swap_int(int *array, int x, int y, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void swap_value(int *x, int *y);
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
void reset_position_pointer(listint_t **current, listint_t **next);
