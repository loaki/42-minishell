/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:43:12 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:45 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cur1;
	unsigned char	*cur2;

	cur1 = (unsigned char*)s1;
	cur2 = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	i = 0;
	while (cur1[i] == cur2[i] && i < n - 1)
		i++;
	return (cur1[i] - cur2[i]);
}
