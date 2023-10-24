#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: The first integer
 * @b: The second integer
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void swap_1(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * sift_down - Sifts down a value in a heap
 * @array: The array to be sorted
 * @start: The start index of the heap
 * @end: The end index of the heap
 * @size: Number of elements in @array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap_idx;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;
		else
		{
			swap_1(&array[root], &array[swap_idx]);
			print_array(array, size);
			root = swap_idx;
		}
	}
}

/**
 * heapify - Converts an array into a heap
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heapify(int *array, size_t size)
{
	ssize_t start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (array && size > 1)
	{
		heapify(array, size);

		while (end > 0)
		{
			swap_1(&array[end], &array[0]);
			print_array(array, size);
			end--;
			sift_down(array, 0, end, size);
		}
	}
}
