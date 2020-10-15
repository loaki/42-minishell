#include "minishell.h"

int			builtin_env(void *cmd, t_data *data)
{
	int			i;
	t_command 	*command;
	i = 0;
	command = cmd;
	while (data->env_tab[i + 1])
	{
		//ft_putstr_fd(data->env_tab[i], command->exit_fd);
		//ft_putstr_fd("\n", command->exit_fd);
		ft_putstr_fd(data->env_tab[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_putstr_fd("_=/usr/bin/env\n", 1);
	//ft_putstr_fd("_=/usr/bin/env\n", command->exit_fd);
	return (SUCCESS);
}