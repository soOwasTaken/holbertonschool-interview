#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: Index of the left subarray
 * @middle: Index of the middle element
 * @right: Index of the right subarray
 * @temp: Temporary array for merging
 **/
void merge(int *array, int left, int middle, int right, int *temp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle, k = 0; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}
	while (i < middle)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = 0, k = left; k < right;)
		array[k++] = temp[i++];
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *temp;

	if (size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	mid = size / 2;
	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);

	merge(array, 0, mid, size, temp);

	free(temp);
}
