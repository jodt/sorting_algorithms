#include "sort.h"
/**
 * bubble_sort - function that sorts
 * an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array of unsorted int
 * @size: size of array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	if (size > 1 && array)
	{
		size_t i = 0;
		size_t j = 0;
		size_t more = 1;
		size_t val;

		while (more == 1)
		{
			more = 0;
			for (i = 0; i < size - 1; i++)
			{
				j = i + 1;
				if (array[i] > array[j])
				{
					val = array[i];
					array[i] = array[j];
					array[j] = val;
					more = 1;
					print_array(array, size);
				}
			}
		}
	}
}
