#include "minishell.h"

int			set_env_var_value(char *key, char *new_value, t_data *data)
{
	t_list		*current;
	t_env		*env;

	current = data->env_list;
	while (current)
	{
		env = current->content;
		if (!ft_strcmp(key, env->key))
		{
			if (env->value)
				free(env->value);
			env->value = new_value;
			return (SUCCESS);
		}
		current = current->next;
	}
	return (ERROR_KEY_NOT_FOUND);
}
