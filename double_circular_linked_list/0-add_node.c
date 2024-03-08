#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list

 *
 * Return: void

 */

List *add_node_end(List **list, char *str)
{
	List *n_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str) {
		free(new_node);
		return (NULL);

	}

	if (*list == NULL) {
		new_node->next = new_node;
		new_node->prev = new_node;

		*list = new_node;
	} else {
		new_node->next = *list;

		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;

		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular linked list

 * @list: Pointer to the head of the linked list
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str) {
	List *new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str) {
		free(new_node);
		return (NULL);
	}

	if (*list == NULL) {
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	} else {
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;

	}

	return (new_node);
}

