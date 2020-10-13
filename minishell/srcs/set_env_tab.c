/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 05:00:32 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/13 07:08:00 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_str_size(t_env *env)
{
	int		i;
	int		size;

	size = 0;
	i = -1;
	while (env->key[++i])
		size++;
	i = -1;
	while (env->value[++i])
		size++;
	size++;
	return (size);
}

static char	*get_env_str(t_env *env)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = get_env_str_size(env);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (env->key[i])
		str[j++] = env->key[i++];
	str[j++] = '=';
	i = 0;
	while (env->value[i])
		str[j++] = env->value[i++];
	str[j] = '\0';
	return (str);
}

static int	fill_env_tab(t_data *data)
{
	int			i;
	char		*last_word;
	t_list		*current;

	i = 0;
	current = data->env_list;
	while (current)
	{
		if (!empty_variable(current->content))
		{
			if (!(data->env_tab[i] = get_env_str(current->content)))
			{
				ft_clean_tab_index(data->env_tab, i);
				data->env_tab = NULL;
				return (ENOMEM);
			}
			i++;
		}
		current = current->next;
	}
	if (!(last_word = ft_str_join("_=", data->last_word)))
		return (ENOMEM);
	data->env_tab[i++] = last_word;
	data->env_tab[i] = NULL;
	return (SUCCESS);
}

static int	get_env_tab_size(t_data *data)
{
	int		size;
	t_list	*current;

	size = 0;
	current = data->env_list;
	while (current)
	{
		if (!empty_variable(current->content))
			size++;
		current = current->next;
	}
	return (size);
}

int			set_env_tab(t_data *data)
{
	if (!(data->env_tab = (char**)malloc(sizeof(*(data->env_tab))
		* (get_env_tab_size(data) + 2))))
		return (ENOMEM);
	return (fill_env_tab(data));
}
