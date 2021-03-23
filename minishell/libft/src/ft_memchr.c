/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:26:46 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:43 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cur;

	cur = (unsigned char*)s;
	while (n-- > 0)
		if (*cur == (unsigned char)c)
			return (cur);
		else
			cur++;
	return (NULL);
}
