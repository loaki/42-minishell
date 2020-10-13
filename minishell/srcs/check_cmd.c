#include "../inc/minishell.h"
/*
bool		inside_quote(char *str, int index)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (i < index)
	{
		if (str[i] == quote)
		{
			if (i == 0 || str[i - 1] != '\\')
				quote = 0;
		}
		else if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			if (i == 0 || str[i - 1] != '\\')
				quote = str[i];
		i++;
	}
	return (quote != 0);
}
*/
//check_syntax_line_ok