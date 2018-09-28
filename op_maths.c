#include "monty.h"

/**
 * add - add the top two elements of the stack.
 * @stk: the stack.
 * @line_number: the linenumber.
 *
 * Return: void
 */
void add(stack_t **stk, unsigned int line_number)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	sum = variables.temp;
	pop(stk, line_number);
	sum += variables.temp;
	pop(stk, line_number);
	variables.temp = sum;
	push(stk, line_number);
}

/**
 * sub - subtracts the top two elements of the stack.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void sub(stack_t **stk, unsigned int line_number)
{
	int diff;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	diff = variables.temp;
	pop(stk, line_number);
	diff = variables.temp - diff;
	pop(stk, line_number);
	variables.temp = diff;
	push(stk, line_number);
}

/**
 * _div - divide the top two elements of the stack.
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void _div(stack_t **stk, unsigned int line_number)
{
	int quote;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	if (variables.temp == 0)
	{
		line_number++;
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	quote = variables.temp->next->n / variables.temp->n;;
	pop(stk, line_number);
	(*stack)->n = quote;
}
/**
 * _mul - function with two arguments
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void _mul(stack_t **stk, unsigned int line_number)
{
	int product;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	product = variables.temp;
	pop(stk, line_number);
	product = variables.temp * product;
	pop(stk, line_number);
	variables.temp = product;
	push(stk, line_number);
}

/**
 * _mod - function with two arguments
 * @stk: the stack.
 * @line_number: the line number.
 *
 * Return: void.
 */
void _mod(stack_t **stk, unsigned int line_number)
{
	int modulus;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		line_number++;
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	if (variables.temp == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stk(stk, line_number);
		exit(EXIT_FAILURE);
	}

	modulus = variables.temp;
	pop(stk, line_number);
	modulus = variables.temp % modulus;
	pop(stk, line_number);
	variables.temp = modulus;
	push(stk, line_number);
}
