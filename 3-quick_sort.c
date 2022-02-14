#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: integers array
 * @size: array size;
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
/**
 * quicksort - sort array on each side of the pivot
 *
 * @array: array
 * @low: first index array
 * @high: last index array
 * @size: size array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}
/**
 * partition - lomuto partition with pivot
 * @array: array
 * @low: first index array
 * @high: last index array
 * @size: array size
 *
 * Return: pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int j;
	int pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_int(array, i, j, size);
		}
	}
	swap_int(array, (i + 1), high, size);
	return (i + 1);
}
/**
 * swap_int - swap values in the array
 * @array: intergers array
 * @x: index of the first value
 * @y: index of the second value
 * @size: array size
 */
void swap_int(int *array, int x, int y, size_t size)
{
	int temp;

	temp = array[x];
	if (array[x] != array[y])
	{
		array[x] = array[y];
		array[y] = temp;

		print_array(array, size);
	}
}
