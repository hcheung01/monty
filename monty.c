#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

char **split_line(char *line);
void readfile(FILE *filename);

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
	while (getline(&buf, &bufsize, filename) != -1)
	{
		tokens = split_line(buf);
		line_number++;
		printf("line number is: %d\n", line_number);
	}
	free(buf);
}

char **split_line(char *line)
{
	size_t count = 0;
	char **tokens, *token;

	printf("PASSING LINE ARGUMENT IS: %s\n", line);
	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	printf("TOKEN1 IS: %s\n", token);
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	while (token != NULL)
	{
		tokens[count] = token;
		token = strtok(NULL, DELIM);
		printf("TOKEN2 IS: %s\n", token);
		count++;
	}
	tokens[count] = NULL;
	return (tokens);
}

