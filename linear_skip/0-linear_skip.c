#include "search.h"
#include <stdio.h>

skiplist_t *find_express(skiplist_t *node, int value);
skiplist_t *linear_search(skiplist_t *node, skiplist_t *express, int value);

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: pointer to the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;

	if (!list)
	{
		return (NULL);
	}

	express = find_express(list, value);
	return linear_search(list, express, value);
}

/**
 * find_express - finds the express node less than or equal to value
 * @node: pointer to the current node in the skip list
 * @value: the value to search for
 * Return: pointer to the found express node
 */
skiplist_t *find_express(skiplist_t *node, int value)
{
	skiplist_t *express = node->express;

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
		for (express = node; express->next; express = express->next);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
node->index, express->index);
	return express;
}

/**
 * linear_search - searches linearly for a value in a skip list
 * @node: pointer to the current node in the skip list
 * @express: pointer to the express node
 * @value: the value to search for
 * Return: pointer to the node where value is found or NULL
 */
skiplist_t *linear_search(skiplist_t *node, skiplist_t *express, int value)
{
	while (node != express->next && node->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
node->index, node->n);
		node = node->next;
	}

	if (node && node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
node->index, node->n);
		return node;
	}
	return NULL;
}
