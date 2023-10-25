#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 * @tmp: temporary array
 * @exp: exponent
 */
void counting_sort1(int *array, size_t size, int *tmp, int exp)
{
	int i, count[10] = {0};

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10] += 1;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		tmp[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = tmp[i];
}

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int *tmp, max, exp;

	if (array == NULL || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;
	max = array[0];
	for (exp = 0; exp < (int)size; exp++)
	{
		if (array[exp] > max)
			max = array[exp];
	}
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort1(array, size, tmp, exp);
		print_array(array, size);
	}
	free(tmp);
}
