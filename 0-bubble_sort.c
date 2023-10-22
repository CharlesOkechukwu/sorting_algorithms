#include "sort.h"

/**
 * bubble_sort - sort an array using the bubble sort algorithim
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int temp, next, swap = 0;
	size_t i;

	if (size < 2 || !array)
	{
		return;
	}
	for (i = 0; i < (size - 1); i++)
	{
		temp = array[i];
		next = array[i + 1];
		if (temp > next)
		{
			array[i] = next;
			array[i + 1] = temp;
			swap = 1;
			print_array(array, size);
		}
	}
	if (swap > 0)
		bubble_sort(array, size);
}
