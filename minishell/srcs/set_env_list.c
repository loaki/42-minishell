/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:05:30 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 07:26:59 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*get_key_from_env_line(char *env_line)
{
	int		size;
	int		i;
	char	*key;

	size = 0;
	while (env_line[size] && !is_end_key(env_line, size))
		size++;
	if (!(key = (char*)malloc(sizeof(*key) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		key[i] = env_line[i];
	key[i] = '\0';
	return (key);
}

char				*get_value_from_env_line(char *env_line)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	while (env_line[i] && env_line[i] != '=')
		i++;
	i = env_line[i] == '=' ? i + 1 : i;
	while (env_line[i + j])
		j++;
	if (!(value = (char*)malloc(sizeof(*value) * (j + 1))))
		return (NULL);
	j = 0;
	while (env_line[i])
		value[j++] = env_line[i++];
	value[j] = '\0';
	return (value);
}

static t_env	*create_new_env_var(char *env_line)
{
	t_env	*new_env_var;

	if (!(new_env_var = (t_env*)malloc(sizeof(*new_env_var))))
		return (NULL);
	new_env_var->key = NULL;
	new_env_var->value = NULL;
	if (!(new_env_var->key = get_key_from_env_line(env_line)))
	{
		clean_env_var(new_env_var);
		return (NULL);
	}
	if (is_initialized(env_line)
		&& !(new_env_var->value = get_value_from_env_line(env_line)))
	{
		clean_env_var(new_env_var);
		return (NULL);
	}
	return (new_env_var);
}

int					add_new_env_var(char *env_line, t_mini *mini)
{
	t_env		*new_env_var;
	t_list		*new_element;

	if (!(new_env_var = create_new_env_var(env_line)))
		return (ENOMEM);
	if (!(new_element = ft_lstnew(new_env_var)))
	{
		clean_env_var(new_env_var);
		return (ENOMEM);
	}
	ft_lstadd_back(&(mini->env_list), new_element);
	return (SUCCESS);
}

int			set_env_list(t_mini *mini, char **env)
{
	int		i;
	int		ret;

	i = -1;
	while (env[++i])
		if (SUCCESS != (ret = add_new_env_var(env[i], mini)))
			return (ret);

	return (SUCCESS);
}