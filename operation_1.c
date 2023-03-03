/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:08:05 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/18 18:28:03 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_head(t_double_list *stack)
{
	t_node	*temp;

	temp = stack->head;
	if (temp == NULL)
		return (0);
	if ((stack->head->next) == NULL)
	{
		stack->head = NULL;
		stack->tail = NULL;
		stack->size = 0;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		temp->next = NULL;
		(stack->size)--;
	}
	return (temp);
}

t_node	*pop_tail(t_double_list *stack)
{
	t_node	*temp;

	temp = stack->tail;
	if (temp == NULL)
		return (0);
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	temp->prev = NULL;
	(stack->size)--;
	return (temp);
}

void	push_head(t_double_list *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
	stack->head->prev = node;
	node->next = stack->head;
	stack->head = node;
	}
	(stack->size)++;
}

void	push_tail(t_double_list *stack, t_node *node)
{
	if (stack->tail == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
	(stack->size)++;
}
