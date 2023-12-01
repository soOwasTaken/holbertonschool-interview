#include "search.h"
#include <math.h>
#include <stdio.h>

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *express;
	if (list == NULL)
	{
		return (NULL);
	}
	node = list;
	express = list->express;
	while (express && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		express->index, express->n);
		node = express;
		express = express->express;
	}
	if (express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
	}
	else
	{
		express = node;
		while (express->next)
		{
			express = express->next;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		node->index, express->index);
	while (node && node->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);
		node = node->next;
	}
	if (node && node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);
	}
	return ((node && node->n == value) ? node : NULL);
}
