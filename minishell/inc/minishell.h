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

# ifndef OPEN_MAX
#  define OPEN_MAX 4000
# endif

bool                    g_sigint;
bool                    g_sigquit;

typedef struct			s_env
{
	char				*var;
	char				*content;
	struct s_env		*next;
}						t_env;

typedef struct			s_data
{
	t_env				*env_list;
}						t_data;

//lib
void	                ft_putstr_fd(char *s, int fd);
int		                get_next_line(int fd, char **line);

//clean
void		            clean_mini(t_data *data);
//error
void		            put_error_msg(int error_code, char *id1, char *id2);
//main
void		            initialize_mini(t_data *data);
//minishell
void		            print_prompt(void);
void		            minishell(t_data *data);
//quit
void		            quit(int code, t_data *data);
//signal
void                    sigint_handler_cmd(int signal);
void                    sigquit_handler_cmd(int signal);
void                    sigint_handler_sh(int signal);
void                    sigquit_handler_sh(int signal);

// env
int						env_init(t_data *data, char **env);
void					display_env(t_data *data);

#endif