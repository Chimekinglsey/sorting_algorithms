#include "sort.h"

void swap(int *x, int *y);
int partition(int *array, size_t size, int min, int max);
void recursion(int *array, size_t size, int min, int max);
void quick_sort(int *array, size_t size);

/**
* swap - swaps two indexes
* @x: first element to swap
* @y: second swap element
* Return - nothing
*/
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
* partition - creates our partition recursively
* @array: contains list of elements to recurse on
* @min: starting index of recursion
* @max: current pivot
* Return - nothing
*/
int partition(int *array, size_t size, int min, int max)
{
	int *pivot, above, below;

	pivot = array + max;
	for (above = below = min; below < max; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
* recursion - creates our partition recursively
* @array: contains list of elements to recurse on
* @min: starting index of recursion
* @max: current pivot
* Return - nothing
*/
void recursion(int *array, size_t size, int min, int max)
{
	int pivot_index;

	if (max - min > 0)
	{
		pivot_index = partition(array, size, min, max);
		recursion(array, size, min, pivot_index- 1);
		recursion(array, size, pivot_index + 1, max);
	}
}

/**
* quick_sort - a program that sorts an int array using quick sort algorithm
* @array: the integer array to be sorted
* @size: length of the array to sort
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursion(array, size, 0, size - 1);
}
