/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 07:28:23 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 07:28:28 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
													void (*clean_fct)())
{
	t_list	*current;
	t_list	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	current = *begin_list;
	while (current && current->next)
	{
		if (!(*cmp)(current->next->content, data_ref))
		{
			tmp = current->next;
			current->next = current->next->next;
			clean_fct(tmp->content);
			free(tmp);
		}
		else
			current = current->next;
	}
	current = *begin_list;
	if (!(*cmp)(current->content, data_ref))
	{
		*begin_list = current->next;
		clean_fct(current->content);
		free(current);
	}
}
