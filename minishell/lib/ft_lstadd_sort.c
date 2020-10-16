/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:27:44 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/16 15:27:55 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_sort(t_list **alst, t_list *new, int sort(void *, void *))
{
	t_list	*current;
	t_list	*previous;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		current = *alst;
		previous = NULL;
		while (current && sort(current->content, new->content) < 0)
		{
			previous = current;
			current = current->next;
		}
		new->next = current;
		if (!previous)
			*alst = new;
		else
			previous->next = new;
	}
}
