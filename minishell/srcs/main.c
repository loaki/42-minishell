#include "../inc/minishell.h"

void		initialize_mini(t_mini *mini)
{
}

int			main(int argc, char **argv, char **env)
{
	t_mini		mini;
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
	minishell(&mini);
	clean_mini(&mini);
	return (0);
}