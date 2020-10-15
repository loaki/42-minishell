#include "minishell.h"

int			set_cwd(t_data, data)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == 0)
		return(errno);
	if (!(data->cwd = ft_strdup(cwd)))
		return(ENOMEM);
	return(SUCCESS);
}

int			main(int argc, char **argv, char **env)
{
	t_data		data;
	int			ret;

	(void)argc;
	(void)argv;

	initialize_mini(&data);
	if (SUCCESS != (ret = set_env_list(&data, env))
		|| SUCCESS != (ret = initialize_last_word(&data))
		|| SUCCESS != (ret = set_path(&data))
		|| SUCCESS != (ret = set_env_tab(&data)))
		quit(EXIT_FAILURE, &data);
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

	minishell(&data);
	clean_mini(&data);
	return (0);
}