/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:42:48 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 01:42:52 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current_element;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		current_element = *alst;
		while (current_element->next)
			current_element = current_element->next;
		current_element->next = new;
	}
}