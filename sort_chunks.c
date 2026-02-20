/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:38:48 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/08 22:31:06 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_numbers_to_a(t_stack **a, t_stack **b)
{
	int	position_of_max;
	int	size_b;

	while (*b)
	{
		position_of_max = get_max_position(*b);
		size_b = ft_lstsize(*b);
		if (position_of_max <= size_b / 2)
		{
			while (position_of_max-- > 0)
				rb(b, 1);
		}
		else
		{
			while (position_of_max++ < size_b)
				rrb(b);
		}
		pa(a, b);
	}
}

void	start_algo_chunks(t_stack **a, t_stack **b)
{
	int	pushed_count;
	int	numbers_in_chunk;

	pushed_count = 0;
	if (ft_lstsize(*a) <= 100)
		numbers_in_chunk = 16;
	else
		numbers_in_chunk = 36;
	while (*a)
	{
		if ((*a)->index <= pushed_count + numbers_in_chunk)
		{
			pb(a, b);
			if ((*b)->index < pushed_count)
				rb(b, 1);
			pushed_count++;
		}
		else
			ra(a, 1);
	}
	return_numbers_to_a(a, b);
}
