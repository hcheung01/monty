#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

char **tokenizer(char *line);
void readfile(FILE *filename);
void *findOps(char *token, int l_n);
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
	int line_number;

	line_number = 0;
	while (getline(&buf, &bufsize, filename) != EOF)
	{
		tokens = tokenizer(buf);
		line_number++;
	}
	free(buf);
}

char **tokenizer(char *line)
{
	size_t count = 0;
	char **tokens, *token;

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
	printf("TOKEN = %s\n", token);
	while (token != NULL && count < 2)
	{
//		findOps(token, count);
		tokens[count] = token;
		token = strtok(NULL, DELIM);
		printf("TOKEN = %s\n", token);
		count++;
	}
	tokens[count] = NULL;
	return (tokens);
}
/*
void *findOps(char *token, int l_n)
{
	int i;

	printf("PASSED TOKEN IS: %s\n", token);
        printf("PASSED LINE NO IS: %d\n", l_n);
	instruction_t all_func[] = {
		{"PUSH", print_All},
		{NULL, NULL}
	};

	for(i = 0; all_func[i].token != NULL; i++)
	{
		if (strcmp(token, all_func[i].[0]) == 0)
			print_All();
			}
}

void print_All(void)
{
	printf("FOUND PUSH\n");
	}*/
