# 0x18 C - Stacks, Queues - LIFO, FIFO
---
## Description

This project in the Low Level Programming series is about:
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables
* How to work with git submodules

## Objective - Create a new interpreter to process Monty files
Monty is a scripting language that is first compiled into Monty Byte codes. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files
and using doubly linked list as stack or queue while being able to perform operations. The program must be able to process user inputted commands for operations like add or multiple, stack or queue and have no memory leaks.

## Files
---
File|Task
---|---
monty.h | Primary header file with all function prototypes
free_stk.c | function to free node
getops.c | function to get operations
monty.c | main function to push/pop operations to stack or queue which is a linked list data structure
op_maths.c | multiple functions for math operations, example: add, sub, mul, div, mod
op_stack.c | function to create a stack with linked list data structure
operations.c | push, pall, pop, pint, swap function to manipulate the stack/queue
operations2.c | function that does no operations, nothin

## Directories
---
Directory Name | Description
---|---
/monty | directory holding all files for Monty interpretor

## How to compile
gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

## More Info
All files is formatted Betty style and checked using betty-style.pl and betty-doc.pl
All header files is guarded

## Author
Heindrick Cheung
Josh Jimenez