/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 07:16:10 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/13 07:33:40 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			set_path(t_data *data)
{
	char		*path;
	char		**path_tab;

	if (!(path = get_env_value("PATH", data)))
	{
		data->path_tab = NULL;
		return (SUCCESS);
	}
	if (!(path_tab = ft_split(path, ':')))
		return (ENOMEM);
	data->path_tab = path_tab;
	return (SUCCESS);
}