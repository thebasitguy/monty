#include "monty.h"

/**
 * execute - executes the opcode
 *
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to the monty file
 * @content: line content
 *
 * Return: nothing
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", node_push}, {"pall", stack_pall}, {"pint", top_pint},
				{"pop", stack_pop},
				{"swap", top_swap},
				{"add", top_add},
				{"nop", stack_nop},
				{"sub", top_sub},
				{"div", top_div},
				{"mul", top_mul},
				{"mod", top_mod},
				{"pchar", top_char},
				{"pstr", top_str},
				{"rotl", stack_rotl},
				{"rotr", stack_rotr},
				{"queue", queue_mode},
				{"stack", stack_mode},
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

