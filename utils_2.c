/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 10:32:03 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/19 11:55:05 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_iszero(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	if (ft_issign(*str))
		str++;
	while (*str && *str == '0')
		str++;
	while (*str && ft_isspace(*str))
		str++;
	if (*str)
		return (0);
	return (1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
	{
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
