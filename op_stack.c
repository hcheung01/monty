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
		line_number++;
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (isascii(variables.temp))
		printf("%c\n", variables.temp);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
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
void pstr(stack_t **stk, __attribute__((unused)) unsigned int line_number)
{
	stack_t *output;

	if (stk == NULL || *stk == NULL || variables.temp == 0)
	{
		line_number++;
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

/**
 * rotl - moves top of the stack to the bottom once.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void rotl(stack_t **stk, __attribute__((unused))unsigned int line_number)
{
	stack_t *topdown;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		return;
	}

	topdown = *stk;

	while (topdown->next != NULL)
		topdown = topdown->next;

	topdown->next = *stk;
	(*stk)->prev = topdown;
	*stk = (*stk)->next;
	(*stk)->prev = NULL;
	topdown->next->next = NULL;
}

/**
 * rotr - moves the bottom of the stack to the top.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void rotr(stack_t **stk, __attribute__((unused))unsigned int line_number)
{
	stack_t *bottomsup;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		return;
	}

	bottomsup = *stk;

	while (bottomsup->next != NULL)
		bottomsup = bottomsup->next;
	bottomsup->next = *stk;
	bottomsup->prev->next = NULL;
	bottomsup->prev = NULL;
	(*stk)->prev = bottomsup;
	*stk = bottomsup;
}
