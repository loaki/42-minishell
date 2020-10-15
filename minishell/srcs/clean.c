/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 06:09:58 by lulebugl          #+#    #+#             */
/*   Updated: 2020/10/12 06:09:58 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		clean_mini(t_data *data)
{
	ft_lstclear(&(data->env_list), clean_env_var);
	if (data->env_tab)
		ft_clean_tab(data->env_tab);
	if (data->last_word)
		free(data->last_word);
	if (data->path_tab)
		ft_clean_tab(data->path_tab);
	initialize_mini(data);
}

void		clean_command(void *content)
{
	t_command	*command;

	command = content;
	if (command->str)
		free(command->str);
	//if (command->last_word)
	//	free(command->last_word);
	//if (command->previous_word)
	//	free(command->previous_word);
	//if (command->fst_arg)
	//	free(command->fst_arg);
	if (command->argv)
		ft_clean_tab(command->argv);
	//ft_lstclear(&(command->redir_list), clean_redir);
	//command->redir_list = NULL;
	//close_clean(&(command->entry_fd));
	//close_clean(&(command->exit_fd));
	free(command);
}