/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:35:45 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:18:53 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned long	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	start = (start > slen) ? slen : start;
	len = (start + len > slen) ? slen - start : len;
	substr = 0;
	if (!(substr = malloc((len + 1) * sizeof(char))))
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
