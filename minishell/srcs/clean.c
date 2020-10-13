/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 06:09:58 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 06:09:58 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		clean_mini(t_data *data)
{
	ft_lstclear(&(data->env_list), clean_env_var);
	if (data->env_tab)
		ft_clean_tab(data->env_tab);
	if (data->last_word)
		free(data->last_word);
	if (data->path_tab)
		ft_clean_tab(data->path_tab);
	initialize_mini(data);
}