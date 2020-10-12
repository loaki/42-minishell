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
	ft_lstclear(&(mini->env_list), clean_env_var);
	if (mini->env_tab)
		ft_clean_tab(mini->env_tab);
	if (mini->last_word)
		free(mini->last_word);
	initialize_mini(mini);
}