/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 07:23:39 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/15 13:51:02 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			compare_env_key(t_env *env, char *key)
{
	return (ft_strcmp(env->key, key));
}

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