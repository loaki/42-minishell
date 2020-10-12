/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:17:55 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 02:13:58 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
				&& str[index] == '+'));
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

void	display_env(t_mini *minishell)
{
	t_list	*tmp;
	t_env	*aff;

	tmp = minishell->env_list;
	while (tmp)
	{
		aff = tmp->content;
		ft_putstr_fd(aff->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(aff->value, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
}