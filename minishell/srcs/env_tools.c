/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchenot <cchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 07:23:39 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/15 15:41:16 by cchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*get_env_value(char *key, t_data *data)
{
	t_list		*current;
	t_env		*env;

	current = data->env_list;
	while (current)
	{
		env = current->content;
		if (!ft_strcmp(key, env->key))
			return (env->value);
		current = current->next;
	}
	return (NULL);
}

int			get_dup_env_var_value(char **str, char *key, t_data *data)
{
	t_list		*current;
	t_env		*env;

	current = data->env_list;
	while (current)
	{
		env = current->content;
		if (!ft_strcmp(key, env->key))
		{
			if (!env_var->value)
				return(ERROR_VALUE_NOT_FOUND);
			if (!(*str = ft_strdup(env_var->value)))
				return(ENOMEM);
			return(SUCCESS);
		}
		current = current->next;
	}
	return (ERROR_KEY_NOT_FOUND);
}

bool		key_not_found(t_data *data, char *key)
{
	t_list		*current;
	t_env		*env_var;

	current = data->env_list;
	while (current)
	{
		env_var = current->content;
		if (ft_strcmp(key, env_var->key) == 0)
			return(false);
		current = current->next;
	}
	return(true);
}

bool		value_not_found(t_data *data, char *key)
{
	t_list		*current;
	t_env		*env_var;

	current = data->env_list;
	while (current)
	{
		env_var = current->content;
		if (ft_strcmp(key, env_var->key) == 0 && env_var->value)
			return(false);
		current = current->next;
	}
	return(true);
}