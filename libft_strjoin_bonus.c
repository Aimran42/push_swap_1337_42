/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strjoin_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:20:19 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/09 22:46:40 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	res_str = (char *)malloc(i + j + 1);
	if (!res_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		res_str[i] = s1[i];
	j = 0;
	while (s2[j])
		res_str[i++] = s2[j++];
	res_str[i] = '\0';
	return (res_str);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_perform_op(char *op, t_stack **a, t_stack **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b, 0);
	else
		ft_error_exit(a, b);
	return (0);
}
