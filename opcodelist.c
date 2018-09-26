#include "monty.h"

void push();
/**
 * findOps - finds OpCode match and then executes the OpCode.
 * @token: token command passed.
 * @stk: the stack.
 * @linenum: the line number.
 *
 * Return: void
 */
void findOps(char *token, stack_t **stk, unsigned int line_number)
{
	int a = 0;
	printf("JOSH FUNCTION IS: %s\n", token);
	instruction_t op[] = {
		{"push", push},
//		{"pall", pall},
//		{"pint", pint},
//		{"pop", pop},
//		{"swap", swap},
		{NULL, NULL}
	};

	while (op[a].opcode != NULL)
	{
		if (strcmp(token, op[a].opcode) == 0)
		{
			op[a].f(stk, line_number);
			return;
		}
		a++;
	}
//	free_stk(stk, line_number);
	exit(EXIT_FAILURE);
}

void push()
{
	printf("PUSHED JOSH AROUND\n");
}
