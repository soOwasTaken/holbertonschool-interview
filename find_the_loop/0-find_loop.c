#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head, *hare = head;

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;      // Moves one step
		hare = hare->next->next;        // Moves two steps

		if (tortoise == hare)
		{
			tortoise = head;            // Reset tortoise to the beginning
			while (tortoise != hare)    // Find the start of the loop
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return tortoise;            // Return the start of the loop
		}
	}

	return NULL; // No loop found
}
