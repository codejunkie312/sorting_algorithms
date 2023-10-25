#include "sort.h"

/**
 * bitonic_swap - swaps two elements in an array
 * @array: array to swap in
 * @i: index of first element
 * @j: index of second element
 * @dir: direction to sort in 1 for ascending, 0 for descending
 */
void bitonic_swap(int *array, int i, int j, int dir)
{
	int tmp;

	if ((array[i] > array[j] && dir == 1) ||
		(array[i] < array[j] && dir == 0))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * bitonic_merge - recursively merges two arrays in bitonic order
 * @array: array to sort
 * @low: lowest index of array
 * @count: number of elements to merge
 * @dir: direction to sort in 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, int low, int count, int dir)
{
	int k, i = low;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
			bitonic_swap(array, i, i + k, dir);
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recur - recursively sorts an array in bitonic order
 * @array: array to sort
 * @size: size of array
 * @low: lowest index of array
 * @count: number of elements to sort
 * @dir: direction to sort in 1 for ascending, 0 for descending
 */
void bitonic_sort_recur(int *array, size_t size, int low, int count, int dir)
{
	int k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%d/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
		print_array(array + low, count);
		bitonic_sort_recur(array, size, low, k, 1);
		bitonic_sort_recur(array, size, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
		printf("Result [%d/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recur(array, size, 0, size, 1);
}
