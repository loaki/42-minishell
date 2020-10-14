#include "minishell.h"

void			put_error_msg(int error_code, char *id1, char *id2)
{
	char	*msg;

	ft_putstr_fd("Minishell: ", 2);
	if (id1)
	{
		ft_putstr_fd(id1, 2);
		ft_putstr_fd(": ", 2);
	}
	if (id2)
	{
		ft_putstr_fd(id2, 2);
		ft_putstr_fd(": ", 2);
	}/*
	if ((msg = get_error_msg(error_code)))
		ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);*/
}