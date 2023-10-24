#include "sort.h"

/**
 * merge - Merges two subarrays of @array
 * @array: The array to be sorted
 * @temp: Temporary array to store the merged subarrays
 * @left: Left subarray
 * @mid: Middle index
 * @right: Right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;
    
    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left);
    printf("[right]: ");
    print_array(array + mid, right - mid);

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i < mid)
        temp[k++] = array[i++];

    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i];
    
    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_helper - Sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: The array to be sorted
 * @temp: Temporary array to store the merged subarrays
 * @left: Left subarray
 * @right: Right subarray
 */
void merge_sort_helper(int *array, int *temp, size_t left, size_t right)
{
    size_t mid = left + (right - left) / 2;

    if (right - left <= 1)
        return;

    merge_sort_helper(array, temp, left, mid);
    merge_sort_helper(array, temp, mid, right);
    merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (!array || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (!temp)
        return;
    
    merge_sort_helper(array, temp, 0, size);
    free(temp);
}
