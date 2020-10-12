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

void		clean_mini(t_mini *mini)
{
	ft_lstclear(&(mini->env_list), clean_env_var);
	if (mini->env_tab)
		ft_clean_tab(mini->env_tab);
	initialize_mini(mini);
}