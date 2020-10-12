/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchenot <cchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:17:55 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 19:18:58 by cchenot          ###   ########.fr       */
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

// RESET			"\033[0m" or 0
// BLACK			"\033[30m"
// RED				"\033[31m"
// GREEN			"\033[32m"
// YELLOW			"\033[33m"
// BLUE				"\033[34m"
// MAGENTA			"\033[35m"
// CYAN				"\033[36m"
// WHITE			"\033[37m"
// BOLDBLACK		"\033[1m\033[30m"
// BOLDRED			"\033[1m\033[31m"
// BOLDGREEN		"\033[1m\033[32m"
// BOLDYELLOW		"\033[1m\033[33m"
// BOLDBLUE			"\033[1m\033[34m"
// BOLDMAGENTA		"\033[1m\033[35m"
// BOLDCYAN			"\033[1m\033[36m"
// BOLDWHITE		"\033[1m\033[37m"

void	display_env_list(t_data *data)
{
	t_list	*tmp;
	t_env	*aff;

	tmp = data->env_list;
	while (tmp)
	{
		aff = tmp->content;
		ft_putstr_fd_and_color(aff->key, 1, 0);
		ft_putstr_fd_and_color("=", 1, 0);
		ft_putstr_fd_and_color(aff->value, 1, 0);
		ft_putstr_fd_and_color("\n", 1, 0);
		tmp = tmp->next;
	}
}

void	display_env(t_data *data)
{
	int i;

	i = -1;
	while (data->env_tab[++i])
	{
		ft_putstr_fd(data->env_tab[i], 1);
		ft_putstr_fd("\n", 1);
	}
}