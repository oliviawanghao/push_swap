/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:40:21 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/19 10:25:10 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_double_list
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_double_list;

int				digit_check(int argc, char **argv);
int				*get_index(int *numbers, int argc);
int				*num_check(int argc, char **argv);

t_node			*pop_head(t_double_list *stack);
t_node			*pop_tail(t_double_list *stack);
void			push_head(t_double_list *stack, t_node *node);
void			push_tail(t_double_list *stack, t_node *node);

t_node			*create_node(int index);
void			init_list(t_double_list *stack);
t_double_list	*create_list(int *index, int argc);
void			free_list(t_double_list *stack);
int				is_sorted(t_double_list *stack);

void			rotate(t_double_list *stack, char *instruction);
void			r_rotate(t_double_list *stack, char *instruction);
void			push(t_double_list *stack_a, t_double_list *stack_b,
					char *instruction);
void			swap(t_double_list *stack, char *instruction);
void			stack_operate(t_double_list *stack_a, t_double_list *stack_b,
					char *instruction);

void			sort_big(t_double_list *stack_a, t_double_list *stack_b);
void			sort_small(t_double_list *stack_a, t_double_list *stack_b);

int				ft_isdigit(int c);
int				ft_issign(int c);
int				ft_isspace(char c);
int				ft_iszero(char *str);
void			*ft_memset(void *b, int c, size_t len);
int				ft_atoi(const char *str);
void			error(void);

#endif