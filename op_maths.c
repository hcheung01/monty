#include "monty.h"

/**
 * add - add the top two elements of the stack.
 * @stk: the stack.
 * @line_num: the linenumber.
 *
 * Return: void
 */
void add(stack_t **stk, unsigned int line_num)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		Error /* need to add to Error function */;
		free_stk(stk, line_num);
		exit(EXIT_FAILURE);
	}

	sum = var.temp;
	pop(stk, line_num);
	sum += var.temp;
	pop(stk, line_num);
	var.temp = sum;
	push(stk, line_num);
}

/**
 * sub - subtracts the top two elements of the stack.
 * @stk: the stack.
 * @line_num: the line number.
 *
 * Return: void.
 */
void sub(stack_t **stk, unsigned int line_num)
{
	int diff;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't subtract, stack is too small\n", line_num);
		free_stk(stk, line_num);
		exit(EXIT_FAILURE);\
	}

	diff = var.temp;
	pop(stk, line_num);
	diff = var.temp - diff;
	pop(stk, line_num);
	var.temp = diff;
	push(stk, line_num);
}
