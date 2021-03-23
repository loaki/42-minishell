/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:55:34 by lucisanc          #+#    #+#             */
/*   Updated: 2021/03/20 15:08:26 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_prompt(void)
{
	char *prompt;

	prompt = ft_strdup("\e[0;91m$USER\x1b[0m:\e[0;96m$PWD\x1b[0m$ ");
	if (prompt && variables_expansions(&prompt, 0) == 0)
		ft_putstr_fd(prompt, STDERR_FILENO);
	else
		ft_putstr_fd("$ ", STDERR_FILENO);
	free(prompt);
	return (0);
}

int	prompt(t_minishell *shell_info)
{
	int		gnl_ret;
	char	*input;

	input = 0;
	while (!shell_info->exit)
	{
		signal(SIGINT, &sigint_handler_prompting);
		signal(SIGQUIT, SIG_IGN);
		print_prompt();
		gnl_ret = get_next_line(STDIN_FILENO, &input);
		signal(SIGQUIT, &sigquit_handler);
		signal(SIGINT, &sigint_handler_executing);
		if (gnl_ret != 1)
		{
			free(input);
			break ;
		}
		shell_info->exit_status = process_input(shell_info, input);
		free(input);
	}
	return (shell_info->exit_status);
}
