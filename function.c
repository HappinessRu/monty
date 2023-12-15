#include "monty.h"
/**
 * read_file - reads a bytecode file
 * @filename: filename
 * @stack: pointer to the top
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t k = 0;
	int count_line = 1;
	instruct_func s;
	int c;
	int r_ead;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((r_ead = getline(&var_global.buffer, &k, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, stack, count_line);
		if (line == NULL || line[0] == '#')
		{
			count_line++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count_line, line);
			exit(EXIT_FAILURE);
		}
		s(stack, count_line);
		count_line++;
	}
	free(var_global.buffer);
	c = fclose(var_global.file);
	if (c == -1)
		exit(-1);
}

/**
 * get_op_func -  checks opcode
 * @str: string
 * Return: returns a functions
 */
instruct_func get_op_func(char *str)
{
	int k;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	k = 0;
	while (instruct[k].f != NULL && strcmp(instruct[k].opcode, str) != 0)
	{
		k++;
	}

	return (instruct[k].f);
}

/**
 * isnumber - checks if string is a number
 * @str: string
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int k;

	if (str == NULL)
		return (0);
	k = 0;
	while (str[k])
	{
		if (str[0] == '-')
		{
			k++;
			continue;
		}
		if (!isdigit(str[k]))
			return (0);
		k++;
	}
	return (1);
}

/**
 * parse_line - parses a line
 * @line: line
 * @stack: stack
 * @line_number: line number
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
