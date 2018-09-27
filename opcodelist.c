#include "monty.h"

/**
 * findOps - finds OpCode match and then executes the OpCode.
 * @token: token command passed.
 * @stk: the stack.
 * @linenum: the line number.
 *
 * Return: void
 */

get_func findOps(char *token)
{
	int a = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
//		{"pint", pint},
		{"pop", pop},
//		{"swap", swap},
		{NULL, NULL}
	};

	while (op[a].opcode != NULL)
	{
		if (strcmp(token, op[a].opcode) == 0)
		{
			return (op[a].f);
		}
		a++;
	}
//	free_stk(stk, line_number);
	exit(EXIT_FAILURE);

}
