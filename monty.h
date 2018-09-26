#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct vars
{
	int temp;
	char check;
}var_t;

extern var_t variables;
var_t variables;

#define DELIM " \n"

void readfile(FILE *filename, stack_t **stk, unsigned int line_number);

void tokenizer(char *line, stack_t **stk, unsigned int line_number);

void findOps(char *token, stack_t **stk, unsigned int line_number);

void free_stk(stack_t **stk, unsigned int line_number);

void push(stack_t **stk, unsigned int line_number);

void pall(stack_t **stk, unsigned int line_number);

void pop(stack_t **stk, unsigned int line_number);

void swap(stack_t **stk, unsigned int line_number);

void pint(stack_t **stk, unsigned int line_number);

int is_num(char *token);

#endif
