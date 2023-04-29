#include "sort.h"

/**
 * swap_ints - a function to swap two integers
 * @a: First integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

/**
* shell_sort - this function sorts an array of integers in ascending order
* @array: the array to sort
* @size: size of array to sort
* Return - Nothing
*/

void shell_sort(int *array, size_t size)
{
        size_t space = 1, i,j;

        if (array == NULL || size < 2)
                return;

        while (space < size / 3)
                space = space * 3 + 1;
	
	for (space = size / 3; space >= 1; space /= 3)
        {
                for (j = space; j < size; j++)
                {
                        i = j;
                        while (i >= space && array[i - space] > array[i])
                        {
                                swap_ints(&array[i], &array[i - space]);
                                i = i - space;
                        }
                }
                                print_array(array, size);
        }
}
