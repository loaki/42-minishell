#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 0
# define FAILURE 1
# define EOF_GNL 0
# define FAILURE_GNL -1

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <signal.h>
# include "../lib/libft.h"

# define SUCCESS 0
# define FAILURE 1

# ifndef OPEN_MAX
#  define OPEN_MAX 4000
# endif

bool                    g_sigint;
bool                    g_sigquit;

typedef struct			s_env
{
	char				*key;
	char				*value;
}						t_env;

typedef struct			s_mini
{
	t_list				*env_list;
}						t_mini;

//lib
void	                ft_putstr_fd(char *s, int fd);
int		                get_next_line(int fd, char **line);

//clean
void		            clean_mini(t_mini *mini);
//error
void		            put_error_msg(int error_code, char *id1, char *id2);
//main
void		            initialize_mini(t_mini *mini);
//minishell
void		            print_prompt(void);
void		            minishell(t_mini *mini);
//quit
void		            quit(int code, t_mini *mini);
//signal
void                    sigint_handler_cmd(int signal);
void                    sigquit_handler_cmd(int signal);
void                    sigint_handler_sh(int signal);
void                    sigquit_handler_sh(int signal);

// env
void					clean_env_var(void *content);
void					ft_lstadd_back_env(t_env **alst, t_env *new);
int						is_end_key(char *str, int index);
bool					is_initialized(char *env_line);

#endif