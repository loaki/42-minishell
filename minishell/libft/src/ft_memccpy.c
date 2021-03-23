/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:37:38 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:42 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*scur;
	unsigned char	*dcur;

	scur = (unsigned char*)src;
	dcur = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dcur[i] = scur[i];
		if (scur[i] == (unsigned char)c)
			return (dcur + i + 1);
		i++;
	}
	return (NULL);
}
