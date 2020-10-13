#include "../inc/minishell.h"

void		print_prompt(void)
{
	ft_putstr_fd("Minishell$ ", 2);
}

void		initialize_mini(t_data *data)
{
	data->env_list = NULL;
	data->env_tab = NULL;
	data->last_word = NULL;
	data->path_tab = NULL;	
	data->cmd_list = NULL;
}

void		minishell(t_data *data)
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
				quit(0, data);
			if (!ft_strcmp(line, "env"))
				display_env(data);			
			manage_line(line, data);
		}
	}
}