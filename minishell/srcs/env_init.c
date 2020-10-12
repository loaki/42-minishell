/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchenot <cchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 04:16:34 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 17:02:26 by cchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	display_env(t_data *data)
{
	t_env	*tmp;

	tmp = data->env_list;
	while (tmp->next)
	{
		printf("%s=%s\n", tmp->var, tmp->content);
		tmp = tmp->next;
	}
	//printf("%s=%s\n", tmp->var, tmp->content);
	free(tmp);
}

char		*ft_strndup(const char *s1, size_t len)
{
	int			i;
	char		*ret;

	if (len < 0)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ret == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && len)
	{
		ret[i] = s1[i];
		i++;
		len--;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	t_env *node;

	if (alst && *alst)
	{
		node = *alst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else if (alst && !(*alst))
		*alst = new;
}

int		get_env(char *str, t_env *list)
{
	int		i;
	int		j;

	i = 0;
	list->content = NULL;
	list->var = NULL;
	while (str[i] && str[i] != '=')
		i++;
	if (!(list->var = ft_strndup(str, i)))
		return (-1);
	i++;
	j = 0;
	while (str[i + j])
		j++;
	if (!(list->content = ft_strndup(str + i, j)))
		return (-1);
	list->next = NULL;
	return (0);
}

int		env_init(t_data *data, char **env)
{
	int		i;
	t_env	*elem;
	t_env	*tmp;

	i = -1;
	if (!(tmp = malloc(sizeof(t_env))))
		return (ENOMEM);
	while (env[++i])
	{
		if (!(elem = malloc(sizeof(t_env))))
		{
			free(tmp);
			return (ENOMEM);
		}
		if (get_env(env[i], elem) != SUCCESS)
		{
			free(tmp);
			return (ENOMEM);
		}
		ft_lstadd_back_env(&tmp, elem);
		if (i == 1)
			data->env_list = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}
