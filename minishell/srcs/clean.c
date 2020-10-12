#include "../inc/minishell.h"

void		clean_mini(t_mini *mini)
{
	ft_lstclear(&(mini->env_list), clean_env_var);
	//initialize_mini(mini);
}