/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_lst_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 06:00:04 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 06:16:44 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
**	EN COURS
*/

/*
int			get_dup_env_var_value(char **str, char *key, t_mini *mini)
{
	t_list		*current;
	t_env		*env;

	current = mini->env_list;
	while (current)
	{
		env = current->content;
		if (!ft_strcmp(key, env->key))
		{
			if (empty_variable(env))
				return (ERROR_VALUE_NOT_FOUND);
			if (!(*str = ft_strdup(env->value)))
				return (ENOMEM);
			return (SUCCESS);
		}
		current = current->next;
	}
	return (ERROR_KEY_NOT_FOUND);
}

int			initialize_lst_word(t_mini *mini)
{
	int		ret;

	if (SUCCESS != (ret = get_dup_env_var_value(&(mini->last_word), "_", mini)))
		return (ret);
	ft_lstremove_if(&(mini->env_list), "_", compare_env_var, clean_env_var);
	return (SUCCESS);
}
*/