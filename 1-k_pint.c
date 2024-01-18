#include "monty.h"

/**
 * k_pint - prints the top stack value
 * @head: stack head
 * @counter: line_number
 *
 * Return: 0
 */

void k_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
