#include "monty.h"
/**
 * _swap - swap top of stack
 * @stack: stack
 * @line_number: number of line
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * _add - add top of stack and second top stack
 * @stack: stack
 * @line_number: number of line
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int z = 0, k = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		k++;
	}

	if (stack == NULL || (*stack)->next == NULL || k <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	z = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = z;
}

/**
 * _nop - nop top of stack
 * @stack: stack
 * @line_number: number of line
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - prints the ASCII value
 * @stack: stack
 * @line_number: number of line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int y;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	y = (*stack)->n;
	if (y > 127 || y < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(y);
	putchar('\n');
}

/**
 * _isalpha - checks if int is in a alphabet
 * @c: c
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
