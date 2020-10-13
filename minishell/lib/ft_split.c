/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 07:28:43 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/13 07:30:32 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	i;
	int		count;

	if (!s)
		return (-1);
	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
	return (count);
}

static void	clean(char **tab, size_t index)
{
	size_t	i;

	if (!tab)
		return ;
	i = -1;
	while (++i < index)
		free(tab[i]);
	free(tab);
}

static int	extract_word(char const *s, char c, char **tab, size_t index)
{
	size_t	i;
	char	*word;

	if (!s || !tab)
		return (-1);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(word = (char*)malloc(sizeof(*word) * (i + 1))))
	{
		clean(tab, index);
		return (-1);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	tab[index] = word;
	return (0);
}

char		**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	**tab;

	if (!s)
		return ((void*)0);
	size = count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (size + 1))))
		return ((void*)0);
	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			if (-1 == extract_word(s + i, c, tab, j))
				return ((void*)0);
			j++;
		}
	tab[j] = (void*)0;
	return (tab);
}
