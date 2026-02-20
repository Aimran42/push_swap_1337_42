/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:26:52 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/10 01:25:35 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**tab;
	int		count;
	t_stack	*a;
	t_stack	*b;

	tab = NULL;
	count = ft_parse_args(ac, av, &tab);
	a = ft_fill_a(tab);
	b = NULL;
	free_array(tab, count);
	if (is_sorted(a))
	{
		ft_stack_clear(&a);
		exit(0);
	}
	ft_handle_sort(&a, &b, count);
	ft_stack_clear(&a);
}
