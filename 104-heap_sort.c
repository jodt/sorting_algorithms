#include "sort.h"
/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: integers array
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = ((int)size / 2 - 1); i >= 0; i--)
		heapify(array, i, size, size);
	for (i = (int)size - 1; i > 0; i--)
	{
		swap_val(array, &array[0], &array[i], size);
		heapify(array, 0, i, size);
	}
}

/**
 * heapify - creates a max heap
 * @array: array uses to create the create the heap
 * @i: element index in the array
 * @heap_size: heap size
 * @size: array size
 */
void heapify(int *array, int i, int heap_size, size_t size)
{
	int bigger = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < heap_size && array[left] > array[bigger])
		bigger = left;

	if (right < heap_size && array[right] > array[bigger])
		bigger = right;

	if (bigger != i)
	{
		swap_val(array, &array[i], &array[bigger], size);
		heapify(array, bigger, heap_size, size);
	}
}
/**
 * swap_val - swap two value
 *
 * @array: array
 * @x: first value
 * @y: second value
 * @size: array size
 */
void swap_val(int *array, int *x, int *y, size_t size)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
	print_array(array, size);
}
