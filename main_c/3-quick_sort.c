#include "sort.h"

/**
* quick_sort - a program that sorts an int array using quick sort algorithm
* @array: the integer array to be sorted
* @size: length of the array to sort
*/
void swap(int *x, int *y);
void recursion(int *array, size_t size, size_t min, size_t max);
size_t partition(int *array, size_t size, size_t min, size_t max);
void quick_sort(int *array, size_t size)
{
	size_t min, max;

	if (array == NULL || size < 2)
		return;
	min = size - size;
	max = size - 1;
	recursion(array, size, min, max);
}

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
size_t partition(int *array, size_t size, size_t min, size_t max)
{
	int pivot = array[max];
	size_t j, i = min;

	for (j = min; j < max; j++)
	{
		if (array[j] <= pivot)
		{
			swap (&array[i], &array[j]);
			print_array(array, size);
			i++;
		}

	}
	swap (&array[i], &array[max]);
	print_array(array, size);
	return i;
}

/**
* recursion - creates our partition recursively
* @array: contains list of elements to recurse on
* @min: starting index of recursion
* @max: current pivot
* Return - nothing
*/
void recursion(int *array, size_t size, size_t min, size_t max)
{
	if (min < max)
	{
		size_t pivot_index;
		pivot_index = partition(array, size, min, max);
		recursion(array, size, min, pivot_index - 1);
		recursion(array, size, pivot_index + 1, max);
	}
}
