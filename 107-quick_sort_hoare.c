#include "sort.h"

/**
 * swap2 - swap two integers
 * @a: first integer
 * @b: second integer
 * @array: array to print
 * @size: size of the array
 */
void swap2(int *a, int *b, int *array, size_t size)
{
    int tmp;

    if (*a != *b)
    {
        tmp = *a;
        *a = *b;
        *b = tmp;
        print_array(array, size);
    }
}

/**
 * hoare_partition - Lomuto partition scheme
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 * Return: index of the pivot
 */
int hoare_partition(int *array, int lo, int hi, size_t size)
{
    int pivot, i, j;

    pivot = array[hi];
    i = lo - 1;
    j = hi + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap2(&array[i], &array[j], array, size);
    }
}

/**
 * quick_sort_hoare_recur - quick sort an array of integers
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 */
void quick_sort_hoare_recur(int *array, int lo, int hi, size_t size)
{
    int pivot;

    if (lo < hi)
    {
        pivot = hoare_partition(array, lo, hi, size);
        quick_sort_hoare_recur(array, lo, pivot, size);
        quick_sort_hoare_recur(array, pivot + 1, hi, size);
    }
}

/**
 * quick_sort_hoare - quick sort an array of integers
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recur(array, 0, size - 1, size);
}
