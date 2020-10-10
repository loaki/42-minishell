/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 04:16:34 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/10 04:53:14 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	display_env(t_mini *mini)
{
	t_env	*tmp;

	tmp = mini->env_list;
	while (tmp->next)
	{
		printf("%s=%s\n", tmp->var, tmp->content);
		tmp = tmp->next;
	}
	/*
	** un segfault est apparu ici donc je verifierai avec vous
	** s'il se reproduit avant de valider ça
	*/
	//tmp->var = NULL;
	//ft_putstr_fd(tmp->var, 2);
	//ft_putstr_fd("=", 2);
	//ft_putstr_fd(tmp->content, 2);
	//ft_putstr_fd("\n", 2);
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

int		env_init(t_mini *minishell, char **env)
{
	int		i;
	t_env	*elem;
	t_env	*tmp;

	i = -1;
	if (!(tmp = malloc(sizeof(t_env))))
		return (ENOMEM);
	minishell->env_list = tmp;
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
		tmp = tmp->next;
	}
	if (minishell->env_list->next)
		minishell->env_list = minishell->env_list->next;
	free(tmp);
	return (0);
}
