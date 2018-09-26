#include "monty.h"

char **tokenizer(char *line, unsigned int line_number);
void readfile(FILE *filename);
void print_All(void);

void main(int argc, char *argv[])
{
	FILE *fp;
	char *filename;
	char *seperate;

	filename = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	readfile(fp);
	fclose(fp);
}

void readfile(FILE *filename)
{
	char *buf = NULL;
	size_t bufsize = 0;
	char *test;
	char **tokens;
	unsigned int line_number;

	line_number = 1;
	while (getline(&buf, &bufsize, filename) != EOF)
	{
		tokens = tokenizer(buf, line_number);
		line_number++;
	}
	free(buf);
}

char **tokenizer(char *line, unsigned int line_number)
{
	size_t count = 0;
	char **tokens, *token;
	stack_t **stk;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	while (token != NULL && count < 2)
	{
		tokens[count] = token;
		token = strtok(NULL, DELIM);
		findOps(tokens[count], stk, line_number);
		count++;
	}
	tokens[count] = NULL;
	return (tokens);
}
