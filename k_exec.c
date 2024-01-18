#include "monty.h"

/**
 * k_exec - executes the opcode
 * @stack: head linked stack list
 * @counter: line counter
 * @file: poiner to monty file
 * @content: content of the line
 *
 *  Return: none
 */

int k_exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", k_push}, {"pall", k_pall}, {"pint", k_pint},
		{"pop", k_pop},
		{"swap", k_swap},
		{"add", k_add},
		{"nop", k_nop},
		{"sub", k_sub},
		{"div", k_div},
		{"mul", k_mul},
		{"mod", k_mod},
		{"pchar", k_pchar},
		{"pstr", k_pstr},
		{"rotl", k_rotl},
		{"rotr", k_rotr},
		{"queue", k_queue},
		{"stack", k_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
