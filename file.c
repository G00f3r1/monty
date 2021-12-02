#include "monty.h"

/**
 * open_file - Opens a file.
 * @file_name: The name of the file.
 */

void open_file(char *file_name)
{
	int permition;
	FILE *fp;

	if (file_name == NULL)
		err(2, file_name);

	permition = access(file_name, R_OK);
	if (permition == -1)
		err(2, file_name);
	fp = fopen(file_name, "r");
	if (fp == NULL)
		err(2, file_name);
	read_file(fp);
	fclose(fp);
}

/**
 * read_file - Reads the content of the file line by line.
 * @fp: pointer to the file
 */

void read_file(FILE *fp)
{
	int line_number;
	int format;
	char *line_pointer;
	size_t len;

	line_pointer = NULL;
	n = 0;
	format = 0;
	
	if (fp == NULL)
		err(2, "file_name");
	for (line_number = 1; getline(&line_pointer, &len, fp) != EOF; line_number++)
	{
		format = parser(line_pointer, line_number, format);
	}
}

/**
 * parser - Separates each line into tokens to determine which function to call.
 * @line_pointer: pointer to a line in the file
 * @line_number: line Number.
 * @format: format specifier.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parser(char *line_pointer, int line_number, int format)
{
	const char *delim;
	char *opcode;
	char *value;

	if (line_pointer == NULL)
		err(4);
	delim = "\n ";
	opcode = strtok(line_pointer, delim);

	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack" == 0))
		return (0);
	find_func(ipcode, value, line_number, format);
	return (format);
}
