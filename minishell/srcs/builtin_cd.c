#include "minishell.h"

int         get_path_cd(char **path, t_command *cmd, t_data data)
{
    int     r;

    if (cmd->argv[1] == 0 ||
    (cmd->argv[1] && (ft_strcmp(cmd->argv[1], "~") == 0)))
    {
        if (key_not_found("HOME", data) || value_not_found("HOME", data))
            return(ERROR_NO_HOME);
        if (SUCCESS != (r = get_dup_env_var_value(path, "HOME", data)))
            return(r);
    }
    else if (ft_strcmp(cmd->argv[1], "-"))
    {
        if (key_not_found("OLDPWD", data) || value_not_found("OLDPWD", data))
            return(ERROR_NO_OLDPWD);
        if (SUCCESS != (r = get_dup_env_var_value(path, "OLDPWD", data)))
            return(r)
    }
    else
    {
        if (!(*path = ft_strdup(cmd->argv[1])))
            return(ENOMEM);
    }
    return(SUCCESS);
}

int         builtin_cd(t_command *cmd, t_data *data)
{
    char    *path;
    int     r;

    if (SUCCESS != (r = get_path_cd(&path, cmd, data)))
    {
        put_error_msg(r, command, NULL);
        return(FAILURE);
    }
    if (SUCCESS != chdir(path))
    {
        r = errno;
        put_error_msg(ret, path, NULL);
        free(path);
        return(FAILURE);
    }
    if (SUCCESS != (r = replace_old_pwd(data)) || SUCCESS != (r = replace_pwd(path, data))
    || SUCCESS != (r = actualize_env_tab(data)))
    {
        free(path);
        put_error_msg(ERROR_FTL, "cd", NULL);
        quit(EXIT_FAILURE, data);
    }
    free(path);
    return(SUCCESS);
}