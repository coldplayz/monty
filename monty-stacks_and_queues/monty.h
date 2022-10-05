#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

#include <sys/types.h>
/*#include <sys/wait.h>*/
#include <sys/stat.h>
#include <sys/fcntl.h>
/*#include <dirent.h>*/

/* MACROS */
#define BUFFER 1024

/* Structures to use */

/**
 * struct info_s - a list of opcode information
 * @num: line number (where instruction is at)
 * @arg: opcode argument if present, else NULL
 */
typedef struct info_s
{
	int num;
	char arg;
} op_t;

/**
 * struct stack_s - doubly linked list rep of a stack / queue
 * @n: integer
 * @prev: pointer to the previous element of stack/queue
 * @next: pointer to the net element of stack/queue
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct track_s - information being tracked
 * @stack: double pointer to the head of the stack / queue
 * @op: pointer to head of op-info list
 */
typedef struct track_s
{
	stack_t **stack;
	op_t op;
} track_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: functiom to handle the opcode
 * Decsription: opcode and its function for
 * stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* global variable */
extern stack_t *stack;

/* Functions */
void push(stack_t **head, unsigned int n);
void pall(stack_t **head, unsigned int n);
void pint(stack_t **head, unsigned int n);
void pop(stack_t **head, unsigned int n);
void add(stack_t **head, unsigned int n);
void swap(stack_t **head, unsigned int n);
void nop(stack_t **head, unsigned int n);

#endif /*MONTY_H*/
