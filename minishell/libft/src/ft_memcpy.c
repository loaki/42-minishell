/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:28:26 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:46 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*scur;
	unsigned char	*dcur;

	scur = (unsigned char*)src;
	dcur = (unsigned char*)dst;
	if (dst == src)
		return (dst);
	while (n-- > 0)
		dcur[n] = scur[n];
	return (dst);
}
