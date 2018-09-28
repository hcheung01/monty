#include "monty.h"

/**
 * tokenizer - function with 3 arguments
 * @input: buffer input
 * @stk: stack argument
 * @line_number: line count
 *
 * Description: break up the buffer into tokens
 * Return: na
 */
void tokenizer(char *input, stack_t **stk, unsigned int line_number)
{
	char *token;
	char *tokens;

	token = strtok(input, " ");
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
	{
		return;
	}
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!is_num(token))
		{
			line_number++;
			fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
			free_stk(stk, line_number);
			exit(EXIT_FAILURE);
		}
		variables.temp = atoi(token);
		findOps(tokens, stk, line_number);
	}
	else
		findOps(token, stk, line_number);
}

/**
 *  is_num - checks if the string is a number
 * @token: the string being checked.
 *
 * Return: 1 if number, 0 if not.
 */
int is_num(char *token)
{
	if (token == NULL)
		return (0);
	if (*token == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
