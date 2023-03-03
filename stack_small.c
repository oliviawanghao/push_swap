/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 14:52:49 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/12 17:41:49 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_operate(t_double_list *stack_a, t_double_list *stack_b)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->head->data;
	b = stack_a->head->next->data;
	c = stack_a->tail->data;
	if (a > b && c > a)
		stack_operate(stack_a, stack_b, "sa\n");
	else if (a > c && b > a)
		stack_operate(stack_a, stack_b, "rra\n");
	else if (a > b && c > b)
		stack_operate(stack_a, stack_b, "ra\n");
	else if (a > b && b > c)
	{
		stack_operate(stack_a, stack_b, "sa\n");
		stack_operate(stack_a, stack_b, "rra\n");
	}
	else
	{
		stack_operate(stack_a, stack_b, "rra\n");
		stack_operate(stack_a, stack_b, "sa\n");
	}
}

void	sort_three(t_double_list *stack_a, t_double_list *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
		stack_operate(stack_a, stack_b, "ra\n");
	else
		three_operate(stack_a, stack_b);
	return ;
}

void	sort_five(t_double_list *stack_a, t_double_list *stack_b)
{
	int	head_data;

	while ((stack_b->size) < 2)
	{
		head_data = stack_a->head->data;
		if (head_data == 0 || head_data == 1)
			stack_operate(stack_a, stack_b, "pb\n");
		else
			stack_operate(stack_a, stack_b, "ra\n");
	}
	sort_three(stack_a, stack_b);
	if (is_sorted(stack_b))
		stack_operate(stack_a, stack_b, "sb\n");
	while ((stack_b->size) > 0)
		stack_operate(stack_a, stack_b, "pa\n");
	return ;
}

void	sort_small(t_double_list *stack_a, t_double_list *stack_b)
{
	if (stack_a->size <= 3)
		sort_three(stack_a, stack_b);
	else
		sort_five(stack_a, stack_b);
}
