#include "monty.h"

/**
 * findOps - finds OpCode match and then executes the OpCode.
 * @token: token command passed.
 * @stk: the stack.
 * @linenum: the line number.
 *
 * Return: void
 */
void findOps(char *token, stack_t **stk, unsigned int linenum)
{
	int a = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	while (op[a].findOps != NULL)
	{
		if (strcmp(token, op[a].findOps) == 0)
		{
			op[a].f(stk, linenum);
			return;
		}
		a++;
	}
	free_stk(stk, linenum);
	exit(EXIT_FAILURE);
}
