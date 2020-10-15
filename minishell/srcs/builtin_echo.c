#include "minishell.h"

int     builtin_echo(t_data *data, t_command *cmd)
{
    int     i;

    if (!cmd->argv[1])
    {
        ft_putstr_fd("\n", cmd->exit_fd);
        return(SUCCESS);
    }
    i = 1;
    if (ft_strcmp(cmd->argv[1], "-n") == 0)
        i++;
    while (cmd->argv[i] && (ft_strcmp(cmd->argv[1], "-n") == 0))
        i++;
    while (cmd->argv[i])
    {
        ft_putstr_fd(cmd->argv[i], cmd->exit_fd);
        if (cmd->argv[i + 1])
            ft_putstr_fd(" ", cmd->exit_fd);
        i++;
    }
    if (ft_strcmp(cmd->argv[1], "-n") == 0)
        ft_putstr_fd("\n", cmd->exit_fd);
    return(SUCCESS);
}