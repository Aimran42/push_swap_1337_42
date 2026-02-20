/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:38:34 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/08 22:46:01 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexing(t_stack *lst)
{
	int		index;
	t_stack	*ptr;
	t_stack	*cur;

	cur = lst;
	while (cur)
	{
		index = 0;
		ptr = lst;
		while (ptr)
		{
			if (cur->nbr > ptr->nbr)
				index++;
			ptr = ptr->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}

t_stack	*ft_fill_a(char **tab)
{
	t_stack	*lst;
	t_stack	*stack_node;
	int		i;

	i = 0;
	lst = NULL;
	while (tab[i])
	{
		stack_node = ft_stack_new(ft_atoi(tab[i]));
		if (!stack_node)
			return (NULL);
		ft_lstadd_back(&lst, stack_node);
		i++;
	}
	indexing(lst);
	return (lst);
}
