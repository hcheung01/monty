#include "monty.h"

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
	char *tokens;
	unsigned int line_number;

	line_number = 1;
	while (getline(&buf, &bufsize, filename) != -1)
	{
		tokens = tokenizer(buf);
		findOps(tokens);
		line_number++;
	}
	free(buf);
}

char *tokenizer(char *line)
{
	char *token;

	token = strtok(line, DELIM);
	if (token == NULL)
	{
		return (NULL);
	}

        token = strtok(NULL, DELIM);
        if (token == NULL)
        {
                return (NULL);
        }
	return (token);
}
