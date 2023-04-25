#include "sort.h"

/**
* selection_sort - sorts an array by replacing the rightmost index with
* with the smallest element in the array
* @array: list of int values to sort
* @size_t: size of the array 
* Return - nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, key;

	for (i = 0; i < size - 1; i++)
	{
		key = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[key])
				key = j;
		}
		if (key != i)
			{
				tmp = array[i];
				array[i] = array[key];
				array[key] = tmp;
				print_array(array, size);
			}
	}
}
