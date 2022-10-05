#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* declare global variables */
extern int top;
extern int top_int;
extern int MAXSIZE;

/* declare the functions (prototypes) */
int peek(int stack[]);
int is_empty(void);
int is_full(void);
int pop(int stack[]);
int push(int stack[], int data);
void convert(int stack[], char infix[], char postfix[]);
int evaluate(int stack[], char postfix[]);

#endif /* STACK_H*/

