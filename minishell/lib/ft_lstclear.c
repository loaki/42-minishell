/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 02:17:48 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 02:17:56 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_element;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	current_element = *lst;
	while (current_element)
	{
		tmp = current_element;
		current_element = current_element->next;
		(*del)(tmp->content);
		free(tmp);
	}
	*lst = (void*)0;
}
