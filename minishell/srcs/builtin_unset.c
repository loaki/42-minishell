#include "minishell.h"

int			actualize_env_tab(t_data *data)
{
	int		ret;

	if (data->env_tab)
	{
		ft_clean_tab(data->env_tab);
		data->env_tab = NULL;
	}
	if ((ret = set_env_tab(data) != SUCCESS))
	{
		put_error_msg(ret, "actualizing environment", NULL);
		return (ret);
	}
	return (SUCCESS);
}

int			actualize_path(t_data *data)
{
	int		ret;

	if (data->path_tab)
	{
		ft_clean_tab(data->path_tab);
		data->path_tab = NULL;
	}
	if (SUCCESS != (ret = set_path(data)))
	{
		put_error_msg(ret, "actualizing path", NULL);
		return (ret);
	}
	return (SUCCESS);
}

bool		check_key_ok(char *key)
{
	int		i;

	if (!*key || !(ft_isalpha(*key) || *key == '_'))
		return (false);
	i = 0;
	while (key[i])
	{
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
			return (false);
		i++;
	}
	return (true);
}

static int	check_unset_args(t_command *command)
{
	int		i;

	i = 1;
	while (command->argv[i])
	{
		if (!check_key_ok(command->argv[i]))
		{
			//put_error_msg(ERROR_INVALID_KEY, "unset", command->argv[i]);
			ft_putstr_fd("Unset : Invalid identifier.", 2);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

// int			compare_env_var(t_env_var *env_var, char *key)
// {
// 	return (ft_strcmp(env_var->key, key));
// }

int			builtin_unset(t_command *command, t_data *data)
{
	int		i;
	int		ret;

	if (!command->argv[1])
		return (SUCCESS);
	i = 0;
	while (command->argv[++i])
	{
		ft_lstremove_if(&(data->env_list), command->argv[i], compare_env_key,
																clean_env_var);
		if (!ft_strcmp(command->argv[i], "PATH")
				&& (SUCCESS != (ret = actualize_path(data))))
		{
			ft_putstr_fd("Unset : Fatal error : minishell must quit.", 2);
			quit(ERROR_FTL, data);
		}
	}
	if (SUCCESS != (ret = actualize_env_tab(data)))
	{
		ft_putstr_fd("Unset : Fatal error : minishell must quit.", 2);
		quit(ERROR_FTL, data);
	}
	return (check_unset_args(command));
}
