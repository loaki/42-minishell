/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:00:39 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:48 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*scur;
	unsigned char		*dcur;

	if (len <= 0 || src == dst)
		return (dst);
	scur = (const unsigned char*)src;
	dcur = (unsigned char*)dst;
	if (scur < dcur)
		while (len--)
			*(dcur + len) = *(scur + len);
	else
		while (len--)
			*dcur++ = *scur++;
	return (dst);
}
