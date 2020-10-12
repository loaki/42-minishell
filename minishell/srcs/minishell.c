#include "../inc/minishell.h"

void		print_prompt(void)
{
	ft_putstr_fd("Minishell$ ", 2);
}

<<<<<<< HEAD
void		minishell(t_data *data)
=======
void		initialize_mini(t_mini *mini)
{
	mini->env_list = NULL;
	mini->env_tab = NULL;
	mini->last_word = NULL;	
}

void		minishell(t_mini *mini)
>>>>>>> 1a1faa4fb971d8710c3fce5193f6a1c4275f81c6
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
			if (!ft_strcmp(line, "exit"))
				quit(0, mini);
			if (!ft_strcmp(line, "env"))
				display_env(mini);			
			//manage_line(line, mini);
		}
	}
}