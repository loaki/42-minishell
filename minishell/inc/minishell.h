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
# define ERROR_KEY_NOT_FOUND -4
# define ERROR_VALUE_NOT_FOUND -5

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

typedef struct			s_data
{
<<<<<<< HEAD
	t_env				*env_list;
}						t_data;
=======
	char				**env_tab;
	char				*last_word;
	t_list				*env_list;
}						t_mini;
>>>>>>> 1a1faa4fb971d8710c3fce5193f6a1c4275f81c6

//lib
void	                ft_putstr_fd(char *s, int fd);
int		                get_next_line(int fd, char **line);

//clean
<<<<<<< HEAD
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
=======
void		            clean_mini(t_mini *mini);

//clean_utils.c
void					ft_clean_tab(char **tab);
void					ft_clean_tab_index(char **tab, int index);

//error
void		            put_error_msg(int error_code, char *id1, char *id2);

//minishell
void		            print_prompt(void);
void		            initialize_mini(t_mini *mini);
void		            minishell(t_mini *mini);

//quit
void		            quit(int code, t_mini *mini);

>>>>>>> 1a1faa4fb971d8710c3fce5193f6a1c4275f81c6
//signal
void                    sigint_handler_cmd(int signal);
void                    sigquit_handler_cmd(int signal);
void                    sigint_handler_sh(int signal);
void                    sigquit_handler_sh(int signal);

<<<<<<< HEAD
// env
int						env_init(t_data *data, char **env);
void					display_env(t_data *data);
=======
//set_env_list.c
char					*get_key_from_env_line(char *env_line);
char					*get_value_from_env_line(char *env_line);
int						add_new_env_var(char *env_line, t_mini *mini);
int						set_env_list(t_mini *mini, char **env);

//set_env_tabs.c
int						set_env_tab(t_mini *mini);

//set_env_utils.c
int						empty_variable(t_env *env);
int						is_end_key(char *str, int index);
bool					is_initialized(char *env_line);
void					clean_env_var(void *content);
void					display_env(t_mini *minishell);

// initialize_last_word.c
int						initialize_last_word(t_mini *mini);
>>>>>>> 1a1faa4fb971d8710c3fce5193f6a1c4275f81c6

#endif