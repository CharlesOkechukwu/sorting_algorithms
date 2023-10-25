#include "sort.h"

/**
 * selection_sort - sort array by selection
 * @array: array to sort in ascending order
 * @size: size of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int old, match;
	size_t i, j, min;

	if (size < 2 || !array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i && array[min] < array[i])
		{
			old = array[i];
			match = array[min];
			array[i] = match;
			array[min] = old;
			print_array(array, size);
		}
	}
}
