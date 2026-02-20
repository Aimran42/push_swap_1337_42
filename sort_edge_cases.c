/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_edge_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:38:03 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/08 22:27:34 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && x > z)
		ra(a, 1);
	else if (y > x && y > z)
		rra(a);
	x = (*a)->index;
	y = (*a)->next->index;
	if (x > y)
		sa(a);
}

static void	sort_4(t_stack **a, t_stack **b)
{
	get_small_to_top(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_stack **a, t_stack **b)
{
	get_small_to_top(a);
	pb(a, b);
	get_small_to_top(a);
	pb(a, b);
	sort_3(a);
	if ((*b)->index < (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}

static void	sort_two(t_stack **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_small_st(t_stack **a, t_stack **b, int count)
{
	if (count == 2)
		sort_two(a);
	else if (count == 3)
		sort_3(a);
	else if (count == 4)
		sort_4(a, b);
	else if (count == 5)
		sort_5(a, b);
}
