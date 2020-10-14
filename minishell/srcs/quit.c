#include "minishell.h"

void		quit(int code, t_data *data)
{
	clean_mini(data);
	exit(code);
}
