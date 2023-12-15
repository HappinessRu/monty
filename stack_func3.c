#include "monty.h"

/**
 * _pstr - mod top of stack
 * @stack: stack
 * @line_number: number of line
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int x = 0;

	(void)line_number;


	while (tmp)
	{
		x = tmp->n;
		if (x == 0 || _isalpha(x) == 0)
			break;
		putchar(x);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - mod top of stack
 * @stack: stack
 * @line_number: number of line
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int a_ux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	a_ux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = a_ux1;
}

/**
 * _rotr - mod top of stack
 * @stack: stack
 * @line_number: number of line
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int a_ux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	a_ux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = a_ux1;
}
