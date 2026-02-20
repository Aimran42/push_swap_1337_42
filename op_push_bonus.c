/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:10:45 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/09 18:18:44 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = tmp->next;
	tmp->next = *to;
	*to = tmp;
}

void	pb(t_stack **a, t_stack **b, int print_move)
{
	push(a, b);
	if (print_move)
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int print_move)
{
	push(b, a);
	if (print_move)
		write(1, "pa\n", 3);
}
