/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 17:54:44 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/19 10:24:04 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && ft_isspace(argv[i][j]))
			j++;
		if (ft_issign(argv[i][j]))
			j++;
		while (argv[i][j] && ft_isdigit(argv[i][j]))
			j++;
		while (argv[i][j] && ft_isspace(argv[i][j]))
			j++;
		if (argv[i][j])
			return (0);
		i++;
	}
	return (1);
}

int	*compare_back(int *numbers, int *index, int i, int j)
{
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (numbers[i - 1] < numbers[j])
				index[j]++;
			j--;
		}
		i--;
	}
	return (index);
}

int	*compare_front(int *numbers, int *index, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				free(index);
				error();
			}
			if (numbers[i] < numbers[j])
				index[j]++;
			j++;
		}
		i++;
	}
	return (compare_back(numbers, index, i, j));
}

int	*get_index(int *numbers, int argc)
{
	int	*index;

	index = (int *)malloc(sizeof(int) * (argc - 1));
	if (!index)
		return (0);
	ft_memset(index, 0, sizeof(int) * (argc - 1));
	return (compare_front(numbers, index, argc));
}

int	*num_check(int argc, char **argv)
{
	int	i;
	int	*numbers;
	int	*index;

	i = 0;
	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (0);
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		if (numbers[i] == 0 && ft_iszero(argv[i + 1]) == 0)
		{
			free(numbers);
			error();
		}
		i++;
	}
	index = get_index(numbers, argc);
	free(numbers);
	return (index);
}
