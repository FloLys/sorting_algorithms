#include "sort.h"

/**
* quick_sort - sort an array of ints with quick sort using Lomuto partition
* and print the array after each swap. The pivot should always be the
* last element of the partition being sorted.
* @array: array
* @size: size
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	qs_recursion(array, 0, size - 1, size);
	print_array(array, size);
}
/**
* qs_recursion - lomuto partitions the array between low and high indexes
* @array: array
* @low: lowest index
* @high: highest index, pivot
*/
void qs_recursion(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low;

	if (low < high)
	{
		for (j = low; j < high; j++)
		{
			if (array[j] <= pivot)
			{
				swap(&array[i], &array[j]);
				i++;
			}
		}
		swap(&array[i], &array[high]);
		print_array(array, size);

		qs_recursion(array, low, i - 1, size);
		qs_recursion(array, i + 1, high, size);
	}
	else
		return;
}
/**
* swap - swaps elements
* @x: x
* @y: y
*/
void swap(int *x, int *y)
{
	int swap;

	swap = *x;
	*x = *y;
	*y = swap;
}
