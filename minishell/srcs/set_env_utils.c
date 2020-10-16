/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:17:55 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/16 17:04:45 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		empty_variable(t_env *env)
{
	if (!env->value)
		return (1);
	return (0);
}

bool		is_initialized(char *env_line)
{
	int		i;

	i = -1;
	while (env_line[++i])
		if (env_line[i] == '=')
			return (true);
	return (false);
}

int		is_end_key(char *str, int index)
{
	return (str[index] == '='
			|| (str[index + 1]
				&& str[index + 1] == '='
				&& str[index] == '+')); // Dans quel cas??
}

void		clean_env_var(void *content)
{
	t_env	*env_var;

	env_var = content;
	if (env_var->key)
		free(env_var->key);
	if (env_var->value)
		free(env_var->value);
	free(env_var);
}
