/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:57:12 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:18:25 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		slen;

	slen = 0;
	while (s1[slen])
		++slen;
	++slen;
	if (!(cpy = malloc(slen * sizeof(char))))
		return (0);
	while (slen--)
		cpy[slen] = s1[slen];
	return (cpy);
}
