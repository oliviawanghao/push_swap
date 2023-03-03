/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 15:22:14 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/18 12:29:54 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	init_list(t_double_list *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_double_list	*create_list(int *index, int argc)
{
	t_double_list	*stack;
	t_node			*temp;
	int				i;

	i = 0;
	stack = (t_double_list *)malloc(sizeof(t_double_list));
	if (!stack)
		return (NULL);
	init_list(stack);
	while (i < argc - 1)
	{
		temp = create_node(index[i]);
		push_tail(stack, temp);
		i++;
	}
	return (stack);
}

void	free_list(t_double_list *stack)
{
	t_node	*temp;

	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	free(stack);
}

int	is_sorted(t_double_list *stack)
{
	int		i;
	int		size;
	t_node	*temp;
	int		temp_one;
	int		temp_two;

	i = 0;
	size = stack->size;
	temp = stack->head;
	while (i < size - 1)
	{
		temp_one = temp->data;
		temp = temp->next;
		temp_two = temp->data;
		if (temp_one > temp_two)
			return (0);
		i++;
	}
	return (1);
}
