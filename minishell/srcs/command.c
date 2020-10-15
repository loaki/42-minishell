#include "minishell.h"

static int	count_command_args(char *str)
{
	int		i;
	int		argc;

	i = 0;
	argc = 0;
	while (str[i])
	{
		if (is_new_arg(str, i))
			argc++;
		i++;
	}
	return (argc);
}

static bool	before_special_char(char *str, int index)
{
	return (!inside_quote(str, index)
			&& (((str[index] == '>'
						|| str[index] == '<'
						|| str[index] == '|'
						|| str[index] == '&')
					&& index > 0
					&& str[index - 1] != str[index])
				|| (str[index] == ';'
					&& index > 0)));
}

static bool	after_special_char(char *str, int index)
{
	return (!inside_quote(str, index)
			&& (((str[index] == '>'
						|| str[index] == '<'
						|| str[index] == '|'
						|| str[index] == '&')
					&& str[index + 1]
					&& str[index + 1] != str[index])
				|| (str[index] == ';'
					&& str[index + 1])));
}


static int	get_size_str_fmt(char *old_str)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (old_str[i])
	{
		if (before_special_char(old_str, i))
			size++;
		if (after_special_char(old_str, i))
			size++;
		size++;
		i++;
	}
	return (size);
}

static char	*create_new_command_str_fmt(char *old_str)
{
	char	*new_str;
	int		size;
	int		i;
	int		j;

	size = get_size_str_fmt(old_str);
	if (!(new_str = (char*)malloc(sizeof(*new_str) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (old_str[i])
	{
		if (before_special_char(old_str, i))
			new_str[j++] = ' ';
		new_str[j++] = old_str[i];
		if (after_special_char(old_str, i))
			new_str[j++] = ' ';
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}


char		*create_new_command_str(char *line)
{
	char	*str;
	char	*str_fmt;
	int		size;
	int		i;

	size = 0;
	while (line[size] && !(!inside_quote(line, size) && (line[size] == '|' || line[size] == ';')))
		size++;
	size++;
	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	if (!(str_fmt = create_new_command_str_fmt(str)))
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (str_fmt);
}

static t_command	*create_new_command(char *line)
{
	t_command	*new_command;

	if (!(new_command = (t_command*)malloc(sizeof(*new_command))))
		return (NULL);
	new_command->str = NULL;
    /*
	new_command->previous_word = NULL;
	new_command->last_word = NULL;
	new_command->argv = NULL;
	new_command->fst_arg = NULL;
	new_command->redir_list = NULL;
	new_command->entry_fd = 0;
	new_command->exit_fd = 1;
    */
	if (!(new_command->str = create_new_command_str(line)))
	{
		//clean_command(new_command);
		return (NULL);
	}
	if (!(new_command->argv = create_new_command_argv(new_command->str)))
	{
		//clean_command(new_command);
		return (NULL);
	}
	return (new_command);
}

int					add_new_command(char *line, t_data *data)
{
	t_command	*new_command;
	t_list		*new_element;

	if (!(new_command = create_new_command(line)))
		return (ENOMEM);
	if (!(new_element = ft_lstnew(new_command)))
	{
		//clean_command(new_command);
		return (ENOMEM);
	}
	ft_lstadd_back(&(data->cmd_list), new_element);
	return (SUCCESS);
}

bool		inside_quote(char *str, int index)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (i < index)
	{
		if (str[i] == quote)
		{
			if (i == 0 || str[i - 1] != '\\')
				quote = 0;
		}
		else if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			if (i == 0 || str[i - 1] != '\\')
				quote = str[i];
		i++;
	}
	return (quote != 0);
}

//new

char		**create_new_command_argv(char *str)
{
	int		i;
	int		j;
	char	**argv;

	if (!(argv = (char**)malloc(sizeof(*argv) * (count_command_args(str) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_new_arg(str, i))
		{
			if (!(argv[j] = create_new_arg(str + i)))
			{
				ft_clean_tab_index(argv, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	argv[j] = NULL;
	return (argv);
}

bool		is_new_arg(char *str, int index)
{
	return (str[index]
			&& !inside_quote(str, index)
			&& str[index] != ' '
			&& (index == 0
				|| (!inside_quote(str, index - 1)
					&& str[index - 1] == ' ')));
}

static char	*create_new_arg(char *str)
{
	int		i;
	int		size;
	char	*arg;

	size = 0;
	while (str[size]
			&& (str[size] != ' ' || inside_quote(str, size)))
		size++;
	if (!(arg = (char*)malloc(sizeof(*arg) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		arg[i] = str[i];
		i++;
	}
	arg[i] = '\0';
	return (arg);
}