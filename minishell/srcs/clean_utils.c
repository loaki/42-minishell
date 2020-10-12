/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 06:09:05 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 06:10:49 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		ft_clean_tab_index(char **tab, int index)
{
	int		i;

	i = -1;
	while (++i < index)
		free(tab[i]);
	free(tab);
}

void		ft_clean_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}