/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:16:50 by ssss              #+#    #+#             */
/*   Updated: 2026/02/08 20:06:43 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small_index(t_stack *a)
{
	int	min_nbr;
	int	index;
	int	min_index;

	min_nbr = INT__MAXX;
	index = 0;
	min_index = 0;
	while (a)
	{
		if (a->nbr < min_nbr)
		{
			min_nbr = a->nbr;
			min_index = index;
		}
		a = a->next;
		index++;
	}
	return (min_index);
}

void	get_small_to_top(t_stack **a)
{
	int	size;
	int	min_index;

	size = ft_lstsize(*a);
	min_index = get_small_index(*a);
	if (size / 2 > min_index)
	{
		while (min_index > 0)
		{
			ra(a, 1);
			min_index--;
		}
	}
	else if (size / 2 <= min_index)
	{
		while (min_index < size)
		{
			rra(a);
			min_index++;
		}
	}
}

int	get_max_position(t_stack *stack)
{
	int	index;
	int	max_index;
	int	max_number;

	index = 0;
	max_index = 0;
	max_number = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max_number)
		{
			max_number = stack->nbr;
			max_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (max_index);
}
