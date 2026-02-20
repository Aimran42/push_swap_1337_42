/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:27:03 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/09 00:38:13 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	*free_w(char **str, int count);
static char	*ft_word(char *s, int start, int end);
static int	split_words(char *s, char c, char **res, int is_word);

int	words(char *str, char c)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	x = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (str[i] == c)
			x = 0;
		i++;
	}
	return (count);
}

static char	*ft_word(char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_w(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	split_words(char *s, char c, char **res, int is_word)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (i < len && s[i] != c && is_word < 0)
			is_word = i;
		else if ((i == len || s[i] == c) && is_word >= 0)
		{
			res[j] = ft_word(s, is_word, i);
			if (!(res[j++]))
				return (free_w(res, j - 1), 1);
			is_word = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		is_word;
	int		check;

	if (!s)
		return (NULL);
	res = malloc((words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	is_word = -1;
	check = split_words(s, c, res, is_word);
	if (check == 1)
		return (NULL);
	return (res);
}
