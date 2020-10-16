#include "minishell.h"

bool		is_modified(char *env_line)
{
	int		i;

	i = 0;
	while (env_line[i] && env_line[i] != '=')
		i++;
	if (i > 0 && env_line[i - 1] == '+')
		return (true);
	return (false);
}

int			actualize_variable(char *arg, char *key, t_data *data)
{
	char	*value;
	char	*previous_value;
	char	*tmp;
	int		ret;

	if (!is_initialized(arg))
		return (SUCCESS);
	if (!(value = get_value_from_env_line(arg)))
		return (ENOMEM);
	if (is_modified(arg) && (previous_value = get_env_var_value(key, data)))
	{
		tmp = value; // inutile je pense
		if (!(value = ft_str_join(previous_value, value)))
		{
			free(tmp);
			return (ENOMEM);
		}
		free(tmp); // inutile je pense
	}
	if (SUCCESS != (ret = set_env_var_value(key, value, data)))
	{
		free(value);
		return (ret);
	}
	return (SUCCESS);
}

int			export_new_variable(char *arg, char *key, t_data *data)
{
	int		ret;

	if (SUCCESS != (ret = add_new_env_var(arg, data)))
		return (ret);
	// if (!is_initialized(arg)
	// 		&& ((!ft_strcmp(key, "PWD") && data->pwd)
	// 			|| (!ft_strcmp(key, "OLDPWD") && data->oldpwd))
	// 		&& (SUCCESS != (ret = restore_pwd_and_oldpwd(key, data))))
	// 	return (ret);
	return (SUCCESS);
}

int			export(char *arg, char *key, t_data *data)
{
	int		ret;

	if (!key_not_found(data, key))
	{
		if (SUCCESS != (ret = actualize_variable(arg, key, data)))
			return (ret);
	}
	else
	{
		if (SUCCESS != (ret = export_new_variable(arg, key, data)))
			return (ret);
	}
	return (SUCCESS);
}

int			manage_export_arg(char *arg, t_data *data)
{
	char	*key;
	int		ret;

	if (!(key = get_key_from_env_line(arg)))
		return (ENOMEM);
	if (!check_key_ok(key))
	{
		free(key);
		return (ERROR_INVALID_KEY);
	}
	if (SUCCESS != (ret = export(arg, key, data)))
	{
		free(key);
		return (ret);
	}
	if (!ft_strcmp(key, "PATH") && SUCCESS != (ret = actualize_path(data)))
	{
		free(key);
		return (ERROR_FTL);
	}
	free(key);
	if (SUCCESS != (ret = actualize_env_tab(data)))
		return (ERROR_FTL);
	return (SUCCESS);
}
