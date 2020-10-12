/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 05:50:58 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 05:56:12 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strcat(char *dest, const char *src)
{
	size_t		i;
	size_t		j;

	if (!dest || !src)
		return ((void*)0);
	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char				*ft_str_join(char const *s1, char const *s2)
{
	size_t		len;
	char		*s3;

	if (!s1 || !s2)
		return ((void*)0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = (char*)malloc(sizeof(*s3) * (len + 1))))
		return ((void*)0);
	*s3 = '\0';
	ft_strcat(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}
