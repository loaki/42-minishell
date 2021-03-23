/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:24:52 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:07:41 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_stdio(int stdio_save[2])
{
	stdio_save[STDIN_FILENO] = dup(STDIN_FILENO);
	stdio_save[STDOUT_FILENO] = dup(STDOUT_FILENO);
}

void	close_pipe(int pipe[2])
{
	if (pipe[0] != -1)
		close(pipe[0]);
	if (pipe[1] != -1)
		close(pipe[1]);
}

void	reset_stdio(int save_stdio[2])
{
	dup2(save_stdio[STDIN_FILENO], STDIN_FILENO);
	dup2(save_stdio[STDOUT_FILENO], STDOUT_FILENO);
}
