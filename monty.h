#ifndef _MONTY_
#define _MONTY_

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

stack_t *new_node(int n);
void free_node(void);
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **stack, unsigned int n_line);
void swap(stack_t **stack, unsigned int n_line);

void error_salida(unsigned int error_code, ...);
void error_salida2(unsigned int error_code, ...);
void add(stack_t **stack, unsigned int n_line);
void sub(stack_t **stack, unsigned int n_line);
void mult(stack_t **stack, unsigned int n_line);
void divi(stack_t **stack, unsigned int n_line);
void op_file(char *file_name);
void r_file(FILE *fd);
int int_line(char *string, int n_line, int format);
void srch_func(char *op_code, char *cmd, int n_line, int format);
void find_func(op_func, char *op_code, char *cmd, int n_line, int format);

#endif
