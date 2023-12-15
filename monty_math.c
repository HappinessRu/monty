#include "monty.h"

/**
 * _sub - sub top of stack
 * @stack: stack
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int s_ub = 0, k = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't s_ub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		k++;
	}

	if (stack == NULL || (*stack)->next == NULL || k <= 1)
	{
		fprintf(stderr, "L%d: can't s_ub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	s_ub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = s_ub;
}

/**
 * _mul - mul top of stack
 * @stack: stack
 * @line_number: number of line
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int a_ux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		a_ux = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= a_ux;
	}
}

/**
 * _div - div top of stack
 * @stack: stack
 * @line_number: number of line
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int d = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't d, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		d = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= d;
	}
}

/**
 * _mod - mod top of stack
 * @stack: stack
 * @line_number: number of line
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int m = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't m, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		m = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= m;
	}
}
