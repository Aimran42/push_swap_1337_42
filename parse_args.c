/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:26:36 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/10 01:35:09 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(int ac, char **av)
{
	int	i;
	int	j;
	int	empty;

	i = 1;
	while (i < ac)
	{
		empty = 1;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ')
				empty = 0;
			j++;
		}
		if (empty == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_parse_args(int ac, char **av, char ***tab)
{
	char	*s;
	int		count;

	count = -1;
	if (ac == 1)
		exit(0);
	if (is_empty(ac, av))
		ft_clean_exit(NULL, NULL);
	s = join_args(ac, av);
	if (!s || !*s)
		ft_clean_exit(NULL, NULL);
	*tab = ft_split(s, ' ');
	if (!*tab)
		ft_clean_exit(s, NULL);
	if (!ft_validate_args(*tab))
		ft_clean_exit(s, *tab);
	count = words(s, ' ');
	free(s);
	return (count);
}
