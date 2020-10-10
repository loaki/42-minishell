#include "../inc/minishell.h"

void	free_env(t_env **lst)
{
	t_env	*current_element;
	t_env	*tmp;

	if (!lst || !*lst)
		return ;
	current_element = *lst;
	while (current_element)
	{
		tmp = current_element;
		current_element = current_element->next;
		if (tmp->var)
			free(tmp->var);
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
	*lst = (void*)0;
}

void		clean_mini(t_mini *mini)
{
	//free_env(&mini->env_list);
	//initialize_mini(mini);
}