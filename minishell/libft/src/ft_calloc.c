/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:47:42 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:08 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void *mem;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	mem = 0;
	if ((mem = malloc(count * size)))
		ft_bzero(mem, count * size);
	return (mem);
}
