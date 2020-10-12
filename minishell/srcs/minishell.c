#include "../inc/minishell.h"

void		print_prompt(void)
{
	ft_putstr_fd("Minishell$ ", 2);
}

void		minishell(t_mini *mini)
{
	char	*line;
	int		ret;

	while (1)
	{
		signal(SIGINT, sigint_handler_cmd);
		signal(SIGQUIT, sigquit_handler_cmd);
		print_prompt();
		line = NULL;
		if (FAILURE_GNL == (ret = get_next_line(0, &line)))
			put_error_msg(FAILURE_GNL, NULL, NULL);
		else
		{
			//signal(SIGINT, sigint_handler_cmd);
			//signal(SIGQUIT, sigquit_handler_cmd);
			if (!strcmp(line, "exit"))
				quit(0, mini);
			if (!strcmp(line, "env"))
				display_env(mini);
			//manage_line(line, mini);
		}
	}
}