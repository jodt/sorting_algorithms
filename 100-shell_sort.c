#include "sort.h"
/**
 * shell_sort - orts an array of integers in ascending
 * order using the Shell sort algorithm
 * using the Knuth sequence.
 * @array: array
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j;

	if (!size)
		return;
	while ((gap * 3 + 1) < (int)size)
		gap = gap * 3 + 1;

	while (gap > 0)
	{

		for (j = 0; j < (int)size - gap; j++)
		{
			i = j;
			while ((i + gap) < (int)size)
			{
				i = i + gap;
			}
			while ((i - gap >= 0))
			{
				if (array[i] < array[i - gap])
				{
					swap_value(&array[i], &array[i - gap]);
				}
				i -= gap;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

/**
 * swap_value - swap two values in the array
 * @x: first value
 * @y: second value
 */
void swap_value(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
