/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:50:25 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/18 17:55:55 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_basic_env(void)
{
	if ((g_env = malloc(sizeof(char*) * 2)))
	{
		g_env[0] = ft_strdup("PATH=/bin");
		g_env[1] = 0;
	}
	return (g_env);
}
