#include "monty.h"

/**
 * push - adds to the top of the stack
 * @stk: the top of stack
 * @line_number: the token line number
 *
 * Return: void
 */
void push(stack_t **stk, unsigned int line_number)
{
	stack_t *new;

	if (stk == NULL)
	{
		fprintf(stderr, "L%d: unknown stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}
	new->n = variables.temp;
	new->prev = NULL;
	new->next = *stk;

	if (*stk != NULL)
		(*stk)->prev = new;
	*stk = new;
}


/**
 * pall - function the prints the stack
 * @stk: the top of stack
 * @line_number: the line number
 *
 * Return: void
 */
void pall(stack_t **stk, unsigned int line_number)
{
	stack_t *print;
	(void)line_number;

	print = *stk;
	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

/**
 * pop - function to remove the top of the stack
 * @stk: the top of the stack
 * @line_number: line number
 *
 * Return: void
 */
void pop(stack_t **stk, unsigned int line_number)
{
	if (stk == NULL || *stk == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stk)->next != NULL)
	{
		*stk = (*stk)->next;
		variables.temp = (*stk)->n;
		free((*stk)->prev);
		(*stk)->prev = NULL;
	}
	else
	{
		free(*stk);
		*stk = NULL;
	}
}

/**
 * pint - function prints the value at the top of the stack
 * @stk: stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stk, unsigned int line_number)
{
	if (*stk == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*stk)->n);
}

/**
 * swap - swapping first two elements on top of stack
 * @stk: stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stk, unsigned int line_number)
{
	int temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = temp;
}
