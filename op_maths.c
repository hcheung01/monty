#include "monty.h"

/**
 * add - add the top two elements of the stack.
 * @stk: the stack.
 * @linenum: the linenumber.
 *
 * Return: void
 */
void add(stack_t **stk, unsigned int linenum)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		Error /* need to add to Error function */;
		free_stk(stk, linenum);
		exit(EXIT_FAILURE);
	}

	sum = var.temp;
	pop(stk, linenum);
	sum += var.temp;
	pop(stk, linenum);
	var.temp = sum;
	push(stk, linenum);
}
