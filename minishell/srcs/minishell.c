#include "../inc/minishell.h"

void		display_prompt(void)
{
	ft_putstr_fd("Minishell$ ", 2);
}

void		minishell(t_mini *mini)
{
	char	*line;
	int		ret;

	while (1)
	{
		display_prompt();
		line = NULL;
		if (FAILURE_GNL == (ret = get_next_line(0, &line)))
			put_error_msg(FAILURE_GNL, NULL, NULL);
		else if (EOF_GNL == ret)
		{
			ft_putstr_fd("exit\n", 2);
			//quit(mini->lst_status, mini);
		}
		else
		{
			ft_putstr_fd(line, 2);
			//signal(SIGINT, sigint_handler_command);
			//signal(SIGQUIT, sigquit_handler_command);
			//manage_line(line, mini);
		}
	}
}