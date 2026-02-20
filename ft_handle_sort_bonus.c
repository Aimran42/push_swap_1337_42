/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sort_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:47:50 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/09 00:37:59 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_stack *head)
{
	while (head->next)
	{
		if (head->nbr > head->next->nbr)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_handle_sort(t_stack **a, t_stack **b, int count)
{
	if (count <= 5)
		sort_small_st(a, b, count);
	else
		start_algo_chunks(a, b);
}
