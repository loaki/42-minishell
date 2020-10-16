#include "minishell.h"

static int			fill_tab(char **tab, t_data *data)
{
	int		i;

	i = -1;
	while (data->env_tab[++i])
		if (!(tab[i] = ft_strdup(data->env_tab[i])))
		{	
			ft_clean_tab(tab);
			return (ENOMEM);
		}
	return (SUCCESS);
}

static void			sort_in_tab(char **tab)
{
	char		*tmp;
	int			i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i + 1] && (ft_strcmp(tab[i], tab[i + 1]) > 0))
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
	}
}

static int			sort_and_display_tab(t_data *data, t_command *command)
{
	char	**tab;
	char	*tmp;
	int		i;

	i = -1;
	while (data->env_tab[i])
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (ENOMEM);
	tab[i + 1] = NULL;
	if (fill_tab(tab, data) != SUCCESS)
		return (ENOMEM);
	sort_in_tab(tab);
	i = -1;
	while (tab[++i + 1])
	{
		//ft_putstr_fd(data->env_tab[i], command->exit_fd);
		//ft_putstr_fd("\n", command->exit_fd);
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
	}
	ft_clean_tab(tab);
	return (SUCCESS);
}

int			builtin_export(t_command *command, t_data *data)
{
	//int		i;
	int		ret;

	if (!command->argv[1])
	{
		if ((ret = sort_and_display_tab(data, command)) != SUCCESS)
			quit(ret, data);
		return (SUCCESS);
	}
	//i = 1;
	// while (command->argv[i])
	// {
	// 	if (SUCCESS != (ret = manage_export_arg(command->argv[i], mini)))
	// 	{
	// 		if (ERROR_FTL == ret)
	// 		{
	// 			put_error_msg(ret, "export", NULL);
	// 			quit(EXIT_FAILURE, mini);
	// 		}
	// 		put_error_msg(ret, "export", command->argv[i]);
	// 		return (FAILURE);
	// 	}
	// 	i++;
	// }
	return (SUCCESS);
}