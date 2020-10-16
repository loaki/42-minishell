#include "minishell.h"

int			actualize_env_tab(t_data *data)
{
	int		ret;

	if (data->env_tab)
	{
		ft_clean_tab(data->env_tab);
		data->env_tab = NULL;
	}
	if (SUCCESS != (ret = set_env_tab(data)))
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