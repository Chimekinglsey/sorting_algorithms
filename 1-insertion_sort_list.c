#include "sort.h"

/**
* bubble_sort - this function sorts an array of integers in ascending order
* @array: the array to sort
* @size: size of array to sort
* Return - Nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j + 1])
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
				}
			}
			else
			{
				print_array(array, size);
			}
		}
	}
}
