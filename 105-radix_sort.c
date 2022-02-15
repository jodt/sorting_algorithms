#include "sort.h"

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix sort algorithm
 * @array: array
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	if (size > 1)
	{
		int divisor = 1, i, j, k = 0, l, loop = 0;
		int *sorted_array;

		loop = find_bigger_number(array, size);
		sorted_array = malloc(sizeof(int) * size);
		if (sorted_array == NULL)
			return;
		while (loop)
		{
			k = 0;
			for (i = 0; i < 10; i++)
			{
				for (j = 0; j < (int)size; j++)
				{
					if (((array[j] / divisor) % 10) == i)
					{
						sorted_array[k] = array[j];
						k++;
					}
				}
			}
			for (l = 0; l < (int)size; l++)
				array[l] = sorted_array[l];
			print_array(array, size);
			divisor *= 10;
			loop--;
		}

		free(sorted_array);
	}
}

/**
 * find_bigger_number - find the largest number
 * @array: array
 * @size: array size
 *
 * Return: number of times the number could be divided by 10
 */
int find_bigger_number(int *array, size_t size)
{
	int max_value, i = 0, loop = 0;

	max_value = array[i];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	while (max_value % 10)
	{
		loop++;
		max_value /= 10;
	}
	return (loop);
}
