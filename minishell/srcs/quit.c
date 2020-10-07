#include "../inc/minishell.h"

void		quit(int code, t_mini *mini)
{
	clean_mini(mini);
	exit(code);
}
