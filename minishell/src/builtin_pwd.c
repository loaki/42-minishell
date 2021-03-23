/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:42:36 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:11:41 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char *cwd;

	if ((cwd = getcwd(NULL, 0)))
		ft_putendl_fd(cwd, STDOUT_FILENO);
	free(cwd);
	return (0);
}
