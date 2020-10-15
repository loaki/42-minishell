#include "minishell.h"

void			launching_loop(t_data *data)
{
	t_list		*current;
	t_list		*previous;

	current = data->cmd_list;
	previous = NULL;
	while (current)
	{
		//launch(current, previous, mini);

        //print cmd
        t_command *c = current->content;
		ft_putstr_fd("--- str --- \n", 1);
	    ft_putstr_fd(c->str, 1);
	    ft_putstr_fd("\n\n", 1);
		ft_putstr_fd("--- argv --- \n", 1);
		for (int i = 0; c->argv[i]; i++)
		{
			ft_putstr_fd(c->argv[i], 1);
			ft_putstr_fd("\n", 1);
			//if (!ft_strcmp(c->argv[i], "unset"))
			//	builtin_unset(c, data);
		}

		previous = current;
		current = current->next;
	}
}