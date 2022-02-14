#include "sort.h"
/**
 * selection_sort - function that sorts
 * an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: array of unsorted int
 * @size: size of array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	if (size > 1 && array)
	{
		size_t i = 0;
		size_t j = 0;
		size_t index;
		size_t value;
		size_t j_comp;
		size_t comp_value;

		for (i = 0; i < size - 1; i++)
		{
			value = array[i];
			for (j = i + 1; j < size; j++)
			{
				if (array[i] > array[j])
				{
					j_comp = array[j];
					if (value > j_comp)
					{
						index = j;
						value = array[j];
					}
				}
			}
			comp_value = array[i];
			array[index] = array[i];
			array[i] = value;
			if (comp_value != value)
			{
				print_array(array, size);
			}
		}}
	else if (size == 2)
	{
		if (array[0] > array[1])
{
			size_t value = array[0];

			array[0] = array[1];
			array[1] = value; }}}
