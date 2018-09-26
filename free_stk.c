#include "monty.h"

/**
 * free_stk - frees the stack
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void free_stk(stack_t **stk, unsigned int line_number)
{
	if (stk == NULL)
		return;
	while (*stk != NULL)
		pop(stk, line_number);
}
