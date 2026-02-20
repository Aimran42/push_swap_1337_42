/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:26:52 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/09 23:03:12 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	char	**tab;
	int		count;
	char	*op;
	t_stack	*a;
	t_stack	*b;

	tab = NULL;
	count = ft_parse_args(ac, av, &tab);
	a = ft_fill_a(tab);
	b = NULL;
	free_array(tab, count);
	op = get_next_line(0);
	while (op)
	{
		ft_perform_op(op, &a, &b);
		free(op);
		op = get_next_line(0);
	}
	if (is_sorted(a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
}
