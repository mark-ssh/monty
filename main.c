#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry 2 the program.
 * @argc: Number of command line arguments.
 * @argv: An array containing the arg.
 * Return: Allways zero.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		error_salida(1);
	op_file(argv[1]);
	free_node();
	return (0);
}
