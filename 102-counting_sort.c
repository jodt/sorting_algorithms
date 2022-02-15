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
		int *new, counter = 0, j = 0, i = 0, k = 0;
		int n_size = size, l = 0;

		for (i = 0; i < n_size; i++)
		{
			if (array[i] > k)
			{
				k = array[i];
			}
		}
		k += 1;
		new = malloc(sizeof(int) * k);
		if (new == NULL)
		{
			return;
		}
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < n_size; j++)
			{
				if (i == array[j])
				{
					counter += 1;
				}}
			new[i] = counter;
		}
		counter = 0;
		for (i = 0; i < k; i++)
		{
			if (new[i] > counter)
			{
				array[l] = i;
				counter += 1;
				l++;
			}}
		print_array(new, k);
		free(new);
	}}
