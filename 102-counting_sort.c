#include "sort.h"
/**
 * counting_sort - function that sorts an array
 * of integers in ascending order using the
 * Counting sort algorithm
 * @array: array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	if (size > 1)
	{
		int *new, counter = 0, j = 0, i = 0, biggest_value = 0;
		int n_size = size, k = 0;

		for (i = 0; i < n_size; i++)
		{
			if (array[i] > biggest_value)
			{
				biggest_value = array[i];
			}
		}
		biggest_value += 1;
		new = malloc(sizeof(int) * biggest_value);
		if (new == NULL)
		{
			return;
		}

		for (i = 0; i < biggest_value; i++)
		{
			for (j = 0; j < n_size; j++)
			{
				if (i == array[j])
				{
					counter += 1;
				}
			}
			new[i] = counter;
		}
		counter = 0;
		for (i = 0; i < biggest_value; i++)
		{
			if (new[i] > counter)
			{
				array[k] = i;
				counter += 1;
				k++;
			}
		}
		print_array(new, biggest_value);
	}
}
