#include "../inc/minishell.h"

<<<<<<< HEAD
void		set_env_list(t_data *data, char **env)
{
	data->env_list = NULL;
	env_init(data, env);
	//display_env(mini);
}

void		initialize_mini(t_data *data)
{
}

=======
>>>>>>> 1a1faa4fb971d8710c3fce5193f6a1c4275f81c6
int			main(int argc, char **argv, char **env)
{
	t_data		data;
	int			ret;

	(void)argc;
	(void)argv;

	initialize_mini(&mini);
	if (SUCCESS != (ret = set_env_list(&mini, env))
		|| SUCCESS != (ret = initialize_last_word(&mini))
		|| SUCCESS != (ret = set_env_tab(&mini)))
		quit(EXIT_FAILURE, &mini);
	/*g_sigint = false;
	g_sigquit = false;
	mini.lst_status = 0;
	mini.exit_stop = false;
	if (SUCCESS != (ret = set_env_list(&mini, env))
		|| SUCCESS != (ret = initialize_lst_word(&mini))
		|| SUCCESS != (ret = increment_shlvl(&mini))
		|| SUCCESS != (ret = set_env_tab(&mini))
		|| SUCCESS != (ret = set_path(&mini))
		|| SUCCESS != (ret = set_cwd(&mini)))
	{
		put_error_msg(ret, NULL, NULL);
		quit(EXIT_FAILURE, &mini);
	}*/
<<<<<<< HEAD
	set_env_list(&data, env);
	minishell(&data);
	clean_mini(&data);
=======

	minishell(&mini);
	clean_mini(&mini);
>>>>>>> 1a1faa4fb971d8710c3fce5193f6a1c4275f81c6
	return (0);
}