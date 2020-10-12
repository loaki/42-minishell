/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_and_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:04:52 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 02:26:49 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_and_color(char *s, int fd, char *color)
{
	if (!color)
		color = "\033[0m";
	if (s)
	{
		if (write(fd, color, ft_strlen(color)) == -1)
			return ;
		if (write(fd, s, ft_strlen(s)) == -1)
			return ;
		if (write(fd, "\033[0m", ft_strlen("\033[0m")) == -1)
			return ;
	}
}
