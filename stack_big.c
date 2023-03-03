/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_stack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:43:27 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/12 17:27:17 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_operate(t_double_list *stack_a, t_double_list *stack_b,
			int size, int max_bits)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = stack_a->head->data;
			if ((num >> i) & 1)
				stack_operate(stack_a, stack_b, "ra\n");
			else
				stack_operate(stack_a, stack_b, "pb\n");
			j++;
		}
		while ((stack_b->size) > 0)
			stack_operate(stack_a, stack_b, "pa\n");
		i++;
	}
}

void	sort_big(t_double_list *stack_a, t_double_list *stack_b)
{
	int	size;
	int	max_bits;

	size = stack_a->size;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
	{
		++max_bits;
	}
	big_operate(stack_a, stack_b, size, max_bits);
}
