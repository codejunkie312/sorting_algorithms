#include <string.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0, *count_array, *output_array, j;
	size_t i;

	if (!array || size < 2)
		return;

	count_array = calloc(max_value + 1, sizeof(int));
	if (!count_array)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
		{
			count_array = realloc(count_array, (array[i] + 1) * sizeof(int));
			if (!count_array)
				return;
			memset(count_array + max_value + 1, 0, (array[i] -
			max_value) * sizeof(int));
			max_value = array[i];
		}
		count_array[array[i]]++;
	}
	for (j = 1; j <= max_value; j++)
		count_array[j] += count_array[j - 1];

	print_array(count_array, max_value + 1);
	output_array = malloc(size * sizeof(int));
	if (!output_array)
	{
		free(count_array);
		return;
	}
	for (j = size - 1; j >= 0; j--)
	{
		output_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}
	memcpy(array, output_array, size * sizeof(int));
	free(count_array);
	free(output_array);
}
