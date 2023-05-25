#include "monty.h"

/**
 * srch_func - Finds the function to be executed.
 * @opcode: Operation code.
 * @cmd: Possible value 4 the operation.
 * @n_line: Line number 4 the opcode.
 * @format: Format specifier should be 0 for Stack or 1 for Queue.
 */
void srch_func(char *opcode, char *cmd, int n_line, int format)
{
	int i;
	int error;

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mult},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;

	for (error = 1, i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			find_func(functions[i].f, opcode, cmd, n_line, format);
			error = 0;
		}
	}
	if (error == 1)
	{
		error_salida(3, n_line, opcode);
	}
}

/**
 * find_func - Finds the required function.
 * @f: Pointer to the function to be called.
 * @op_code: String representing the opcode.
 * @cmd: String representing a numeric value.
 * @n_line: Line number 4 the instruction.
 * @format: Format specifier.
 */
void find_func(op_func f, char *op_code, char *cmd, int n_line, int format)
{
	stack_t *node;
	int error;
	int i;

	error = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (cmd != NULL && cmd[0] == '-')
		{
			cmd = cmd + 1;
			error = -1;
		}

		if (cmd == NULL)
		{
			error_salida(5, n_line);
		}


		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (isdigit(cmd[i]) == 0)
			{
				error_salida(5, n_line);
			}

		}

		node = new_node(atoi(cmd) * error);
		if (format == 0)
			f(&node, n_line);
		if (format == 1)
			add_queue(&node, n_line);
	}
	else
		f(&head, n_line);
}
