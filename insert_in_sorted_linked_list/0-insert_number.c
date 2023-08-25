#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the beginning of the list
 * @number: number to insert into the list
 * 
 * Return: address of the new node or NULL if failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = NULL;
    listint_t *current = NULL;
    listint_t *prev = NULL;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    current = *head;
    while (current != NULL && current->n < number)
    {
        prev = current;
        current = current->next;
    }

    new_node->next = current;
    prev->next = new_node;

    return (new_node);
}