#include "sort.h"

/**
* selection_sort - sorts an array of ints with selection sort
* and prints the array after each swap
* @array: array
* @size: size
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, swap, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			swap = array[i];
			array[i] = array[min];
		    array[min] = swap;
			print_array(array, size);
		}
	}
}
