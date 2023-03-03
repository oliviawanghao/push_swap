/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:34:36 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/19 11:20:46 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	nb;

	sign = 1;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	if (!*str || ft_isspace(*str))
		error();
	while (*str && ft_isdigit(*str))
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	nb = nb * sign;
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	else
		return (nb);
}
