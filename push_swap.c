/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:06:13 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/19 11:56:10 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(int argc, t_double_list *stack_a, t_double_list *stack_b)
{
	if (argc > 6)
		sort_big(stack_a, stack_b);
	else
		sort_small(stack_a, stack_b);
	free(stack_b);
	free_list(stack_a);
}

int	main(int argc, char **argv)
{
	int				*index;
	t_double_list	*stack_a;
	t_double_list	*stack_b;

	if (argc > 1)
	{
		if (!digit_check(argc, argv))
			error();
		index = num_check(argc, argv);
		stack_a = create_list(index, argc);
		free(index);
		if (is_sorted(stack_a))
		{
			free_list(stack_a);
			exit(0);
		}
		stack_b = (t_double_list *)malloc(sizeof(t_double_list));
		if (!stack_b)
			return (1);
		init_list(stack_b);
		sort_stack(argc, stack_a, stack_b);
	}
	exit(0);
}

// t_node			*temp;
// temp = stack_a->head;
// while (temp)
// {
// 	if (temp->next == NULL)
// 		printf("%d\n", temp->data);
// 	else
// 		printf("%d <-> ", temp->data);
// 	temp = temp->next;
// }
// printf("stack a is sorted: %i\n", is_sorted(stack_a));
// system("leaks push_swap");