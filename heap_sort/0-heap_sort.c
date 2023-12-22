#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - Converts an array into a heap from a given node
 * @array: The array to be heapified
 * @size: The size of the entire array
 * @i: The current index
 * @total_size: Total size of the array for printing
 */
void heapify(int *array, size_t size, int i, size_t total_size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
