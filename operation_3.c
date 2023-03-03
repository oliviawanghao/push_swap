/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 16:30:48 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/13 15:50:48 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_double_list *stack, char *instruction)
{
	push_tail(stack, pop_head(stack));
	write(1, instruction, 3);
}

void	r_rotate(t_double_list *stack, char *instruction)
{
	push_head(stack, pop_tail(stack));
	write(1, instruction, 4);
}

void	push(t_double_list *stack_a, t_double_list *stack_b, char *instruction)
{
	push_head(stack_a, pop_head(stack_b));
	write(1, instruction, 3);
}

void	swap(t_double_list *stack, char *instruction)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = pop_head(stack);
	temp2 = pop_head(stack);
	push_head(stack, temp1);
	push_head(stack, temp2);
	write(1, instruction, 3);
}

void	stack_operate(t_double_list *stack_a, t_double_list *stack_b,
			char *instruction)
{
	if (strcmp(instruction, "ra\n") == 0)
		rotate(stack_a, instruction);
	else if (strcmp(instruction, "rb\n") == 0)
		rotate(stack_b, instruction);
	else if (strcmp(instruction, "rra\n") == 0)
		r_rotate(stack_a, instruction);
	else if (strcmp(instruction, "rrb\n") == 0)
		r_rotate(stack_b, instruction);
	else if (strcmp(instruction, "sa\n") == 0)
		swap(stack_a, instruction);
	else if (strcmp(instruction, "sb\n") == 0)
		swap(stack_b, instruction);
	else if (strcmp(instruction, "pa\n") == 0)
		push(stack_a, stack_b, instruction);
	else if (strcmp(instruction, "pb\n") == 0)
		push(stack_b, stack_a, instruction);
}
