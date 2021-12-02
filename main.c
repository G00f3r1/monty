#include "monty.h"

/**
 * main - Entery Point
 * @argc: Number of arguments
 * @argv: An array containing the arguments.
 * Return: 0 Always.
 */

int main(int argc, char **argv)
{
	if (argc < 2 || > 2)
		err(1);
	open_file(argv[1]);
	return (0);
}
