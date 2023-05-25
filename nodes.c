#include "monty.h"

/**
 * add_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @n_line: Interger representing the line number of of the opcode.
 */
void add_queue(stack_t **new_node, unsigned int n_line)
{
	stack_t *tmp;
	(void) n_line;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

/**
 * push- Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @n_line: Interger representing the line number of of the opcode.
 */
void push(stack_t **new_node, unsigned int n_line)
{
	stack_t *tmp;
	(void) n_line;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	tmp->prev = NULL;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;

}

/**
 * pall - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n_line: Interger representing the line number of of the opcode.
 */
void pall(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	(void) n_line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n_line: Interger representing the line number of of the opcode.
 */
void pop(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		error_salida2(7, n_line);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @n_line: Interger representing the line number of of the opcode.
 */
void pint(stack_t **stack, unsigned int n_line)
{
	if (stack == NULL || *stack == NULL)
		error_salida2(6, n_line);

	printf("%d\n", (*stack)->n);
}
