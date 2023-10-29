#include "sort.h"

/**
 * quick_sort - sort array using quick sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;
	low = 0;
	high = size - 1;
	quick_sort_arr(array, low, high, size);
}

/**
 * quick_sort_arr - sort array with quick sort algorithm
 * @array: array ot sort
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort_arr(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high <= low)
		return;
	pivot = partition(array, low, high, size);
	quick_sort_arr(array, low, pivot - 1, size);
	quick_sort_arr(array, pivot + 1, high, size);
}

/**
 * partition - swap elements and partition array
 * @array: array to partition
 * @low: low of the array
 * @high: high of the array
 * @size: array size
 *
 * Return: index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (j != i)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (pivot < array[i])
	{
		temp =  array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
