/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:15:55 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:17:28 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*todel;

	if (!lst || !del)
		return ;
	todel = *lst;
	while (todel)
	{
		*lst = (*lst)->next;
		del(todel->content);
		free(todel);
		todel = *lst;
	}
}
