/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:35:45 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/09 16:06:48 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_digit(char d)
{
	return (d >= '0' && d <= '9');
}

int	is_sign(char s)
{
	return (s == '+' || s == '-');
}

int	check_arr_numbers(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		if (is_sign(array[i][j]))
			j++;
		if (!is_digit(array[i][j]))
			return (0);
		while (array[i][j])
		{
			if (!is_digit(array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_overflow(char **array)
{
	long long	n;
	int			i;

	i = 0;
	while (array[i])
	{
		n = ft_atoi(array[i]);
		if (n < INT__MIN || n > INT__MAXX)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicated_number(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
