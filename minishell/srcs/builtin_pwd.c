#include "minishell.h"

int     builtin_pwd(t_data *data, t_command *cmd)
{
    ft_putstr(data, cmd->exit_fd);
    ft_putstr("\n", cmd->exit_fd);
    return(SUCCESS);
}