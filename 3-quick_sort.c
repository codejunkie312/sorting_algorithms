#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in @array
 * Return: Index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j;

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
	return (i);
}

/**
 * quicksort_helper - Quick sort helper
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: Number of elements in @array
 */
void quicksort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort_helper(array, low, pivot - 1, size);
		quicksort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	quicksort_helper(array, 0, size - 1, size);
}
