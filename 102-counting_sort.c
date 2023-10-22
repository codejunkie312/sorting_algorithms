#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
	void counting_sort(int *array, size_t size)
{
	int max_value = 0, *count_array, i, j;
	size_t k;

	if (!array || size < 2)
		return;

	max_value = array[0];
	for (k = 1; k < size; k++)
	{
		if (array[k] > max_value)
			max_value = array[k];
	}

	count_array = malloc((max_value + 1) * sizeof(int));
	if (!count_array)
		return;

	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;

	for (k = 0; k < size; k++)
		count_array[array[k]]++;

	print_array(count_array, max_value + 1);

	j = 0;
	for (i = 0; i <= max_value; i++)
	{
		while (count_array[i] > 0)
		{
			array[j++] = i;
			count_array[i]--;
		}
	}
	free(count_array);
}
