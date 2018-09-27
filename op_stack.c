#include "monty.h"

/**
 * pchar - prints the first char in the top of the stack.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void pchar(stack_t **stk, unsigned int line_number)
{
	if (stk == NULL || *stk == NULL)
	{
		fprintf(stderr, "can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (isascii(variables.temp))
		printf("%c\n", variables.temp);
	else
	{
		fprintf(stderr, "can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints a string from the stack.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void pstr(stack_t **stk, unsigned int line_number)
{
	stack_t *output;

	if (stk == NULL || *stk == NULL || variables.temp == 0)
	{
		printf("\n");
		return;
	}

	output = *stk;

	while (output != NULL && output->n != 0 && isascii(output->n))
	{
		printf("%c", output->n);
		output = output->next;
	}
	printf("\n");
}
