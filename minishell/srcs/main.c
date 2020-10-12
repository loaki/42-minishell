#include "../inc/minishell.h"

void		set_env_list(t_data *data, char **env)
{
	data->env_list = NULL;
	env_init(data, env);
	//display_env(mini);
}

void		initialize_mini(t_data *data)
{
}

int			main(int argc, char **argv, char **env)
{
	t_data		data;
	int			ret;

	(void)argc;
	(void)argv;

	/*g_sigint = false;
	g_sigquit = false;
	initialize_mini(&mini);
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
	set_env_list(&data, env);
	minishell(&data);
	clean_mini(&data);
	return (0);
}