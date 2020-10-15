#include "minishell.h"

char	*extend_path(char *old_path, char *new_dir)
{
	char	*tmp_path;
	char	*new_path;

	if (!(tmp_path = ft_strjoin(old_path, "/")))
		return (NULL);
	new_path = ft_strjoin(tmp_path, new_dir);
	free(tmp_path);
	return (new_path);
}

int	get_previous_pwd(char **pwd, char *path, t_data *data)
{
	char	cwd[PATH_MAX];

	if (!getcwd(cwd, PATH_MAX))
	{
		put_error_msg(errno, "cd", "getcwd");
		if (!(*pwd = extend_path(data->cwd, path)))
			return (ENOMEM);
	}
	else if (!(*pwd = ft_strdup(cwd)))
		return (ENOMEM);
	return (SUCCESS);
}

int			replace_old_pwd(t_data *data)
{
	int		ret;
	char	*oldpwd;

	oldpwd = NULL;
	if ((key_not_found("PWD", data) || value_not_found("PWD", data)))
	{
		if (data->pwd && !(oldpwd = ft_strdup(data->pwd)))
			return (ENOMEM);
	}
	else if (SUCCESS != (ret = get_dup_env_var_value(&oldpwd, "PWD", data)))
		return (ret);
	if (data->oldpwd)
		free(data->oldpwd);
	if (key_not_found("OLDPWD", data))
		data->oldpwd = oldpwd;
	else
	{
		data->oldpwd = NULL;
		if (SUCCESS != (ret = set_env_var_value("OLDPWD", oldpwd, data)))
		{
			free(oldpwd);
			return (ret);
		}
	}
	return (SUCCESS);
}

int			replace_pwd(char *path, t_data *data)
{
	int		ret;
	char	*pwd;

	if (SUCCESS != (ret = get_previous_pwd(&pwd, path, data)))
		return (ret);
	free(data->cwd);
	if (!(data->cwd = ft_strdup(pwd)))
		return (ENOMEM);
	if (data->pwd)
		free(data->pwd);
	if (key_not_found("PWD", data))
		data->pwd = pwd;
	else
	{
		data->pwd = NULL;
		if (SUCCESS != (ret = set_env_var_value("PWD", pwd, data)))
		{
			free(pwd);
			return (ret);
		}
	}
	return (SUCCESS);
}

int			restore_pwd_and_oldpwd(char *key, t_data *data)
{
	char	*value;
	int		ret;

	if ((!ft_strcmp(key, "PWD")
				&& !(value = ft_strdup(data->pwd)))
			|| (!ft_strcmp(key, "OLDPWD")
				&& !(value = ft_strdup(data->oldpwd))))
		return (ENOMEM);
	if (SUCCESS != (ret = set_env_var_value(key, value, data)))
	{
		free(value);
		return (ret);
	}
	if (!ft_strcmp(key, "PWD"))
	{
		free(data->pwd);
		data->pwd = NULL;
	}
	if (!ft_strcmp(key, "OLDPWD"))
	{
		free(data->oldpwd);
		data->oldpwd = NULL;
	}
	return (SUCCESS);
}