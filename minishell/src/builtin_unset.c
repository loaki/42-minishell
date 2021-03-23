/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:32:46 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:11:48 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unset_error(char *arg)
{
	ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	return (1);
}

int			ft_unset(char **args)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (args[i])
	{
		if (ft_strchr(args[i], '=') || check_var_syntaxe(args[i]))
			error = unset_error(args[i]);
		else if (ft_find_in_env(args[i]))
			if (ft_remove_from_env(args[i]))
				return (1);
		++i;
	}
	return (error);
}
