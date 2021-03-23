/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:06:56 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:18:20 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strclen(const char *s, char c)
{
	int size;

	if (!s)
		return (0);
	size = 0;
	while (s[size] && s[size] != c)
		++size;
	return (size);
}
