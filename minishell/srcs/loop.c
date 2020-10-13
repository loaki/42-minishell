#include "../inc/minishell.h"

void			launching_loop(t_mini *mini)
{
	t_list		*current;
	t_list		*previous;

	current = mini->cmd_list;
	previous = NULL;
	while (current)
	{
		//launch(current, previous, mini);

        //print cmd
        t_command *c = current->content;
	    ft_putstr_fd(c->str, 1);
	    ft_putstr_fd("\n", 1);

		previous = current;
		current = current->next;
	}
}