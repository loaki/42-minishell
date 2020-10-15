/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_last_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 06:00:04 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/15 13:50:47 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			search_key_in_env(char **str, char *key, t_data *mini)
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

int			initialize_last_word(t_data *mini)
{
	int		ret;

	if (SUCCESS != (ret = search_key_in_env(&(mini->last_word), "_", mini)))
		return (ret);
	ft_lstremove_if(&(mini->env_list), "_", compare_env_key, clean_env_var);
	return (SUCCESS);
}
