/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:21:44 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/09 16:05:50 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(int ac, char **av)
{
	char	*res;
	char	*s1;
	int		i;

	i = 1;
	res = ft_strdup(av[i++]);
	if (!res)
		ft_error();
	while (i < ac)
	{
		s1 = res;
		res = ft_strjoin(s1, " ");
		free(s1);
		if (!res)
			ft_error();
		s1 = res;
		res = ft_strjoin(s1, av[i]);
		free(s1);
		if (!res)
			ft_error();
		i++;
	}
	return (res);
}

void	free_array(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
}

void	ft_clean_exit(char *s, char **tab)
{
	if (tab)
		free_array(tab, words(s, ' '));
	if (s)
		free(s);
	ft_error();
}

int	ft_validate_args(char **array)
{
	return (check_arr_numbers(array) && check_overflow(array)
		&& check_duplicated_number(array));
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
