/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:02:52 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:58 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int un;

	un = (n < 0) ? -n : n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (un >= 10)
		ft_putnbr_fd((un / 10), fd);
	ft_putchar_fd((un % 10) + '0', fd);
}
