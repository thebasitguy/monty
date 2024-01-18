#include "monty.h"

/**
 * queue_mode - indicates the program is in the queue mode
 *
 * @head: stack head
 * @counter: line_number
 *
 * Return: nothing
 */

void queue_mode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue_tstack - add node to the tail stack
 *
 * @n: new_value
 * @head: head of the stack
 *
 * Return: nothing
 */

void addqueue_tstack(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
