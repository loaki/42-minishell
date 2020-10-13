#include "../inc/minishell.h"

bool		is_new_command(char *str, int index)
{
	return (str[index]
			&& !inside_quote(str, index)
			&& (index == 0
				|| (!inside_quote(str, index - 1)
					&& (str[index - 1] == ';' || str[index - 1] == '|'))));
}

int			parse_line(char *line, t_data *data)
{
	int		i;
	int		ret;

	i = 0;
	while (line[i])
	{
		if (is_new_command(line, i))
		{
			if (SUCCESS != (ret = add_new_command(line + i, data)))
				return (ret);
		}
		i++;
	}
	//return (set_last_and_previous_word(mini));
	return (SUCCESS);
}
/*
static int	set_last_and_previous_word(t_mini *mini)
{
	t_list		*current;
	t_command	*command;
	t_command	*nxt_command;
	char		*last_word;

	current = mini->cmd_list;
	while (current)
	{
		command = current->content;
		nxt_command = current->next ? current->next->content : NULL;
		last_word = ft_tablast(command->argv);
		if (last_word
				&& (!(command->last_word = ft_strdup(last_word))
					|| (nxt_command
						&& !(nxt_command->previous_word =
							ft_strdup(last_word)))))
			return (ENOMEM);
		current = current->next;
	}
	return (SUCCESS);
}
*/

void	manage_line(char *line, t_data *data)
{
	int			ret;

	//sigint_check(mini);
	//sigquit_check(mini);
	if (SUCCESS != (ret = parse_line(line, data)))
	{
		free(line);
		//ft_lstclear(&(mini->cmd_list), clean_command);
		data->cmd_list = NULL;
		put_error_msg(ret, "line parsing", NULL);
		//mini->lst_status = ret;
		return ;
	}
	free(line);
	/*
	if (!check_syntax_line_ok(mini))
	{
		put_error_msg(ERROR_SYNTAX, NULL, NULL);
		mini->lst_status = (unsigned char)ERROR_SYNTAX;
	}

	else
		launching_loop(mini);
	//ft_lstclear(&(mini->cmd_list), clean_command);
	mini->cmd_list = NULL;
	*/
	launching_loop(data);
}