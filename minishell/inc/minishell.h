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

typedef struct			s_command
{
	char				*str;
}						t_command;

typedef struct			s_data
{
	char				**env_tab;
	char				**path_tab;
	char				*last_word;
	char				*cwd;
	t_list				*env_list;
	t_list				*cmd_list;
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
void		            clean_mini(t_data *mini);

//clean_utils.c
void					ft_clean_tab(char **tab);
void					ft_clean_tab_index(char **tab, int index);

//error
void		            put_error_msg(int error_code, char *id1, char *id2);

//quit
void		            quit(int code, t_data *mini);

//signal
void                    sigint_handler_cmd(int signal);
void                    sigquit_handler_cmd(int signal);
void                    sigint_handler_sh(int signal);
void                    sigquit_handler_sh(int signal);

// env
int						env_init(t_data *data, char **env);
int						actualize_path(t_data *data);
int						actualize_env_tab(t_data *data);

// set_env_list.c
char					*get_key_from_env_line(char *env_line);
char					*get_value_from_env_line(char *env_line);
int						add_new_env_var(char *env_line, t_data *data);
int						set_env_list(t_data *data, char **env);
//set_env_tabs.c
int						set_env_tab(t_data *data);
//set_env_utils.c
int						empty_variable(t_env *env);
int						is_end_key(char *str, int index);
bool					is_initialized(char *env_line);
void					clean_env_var(void *content);
//builtin_env.c
int						builtin_env(void *command, t_data *data);
//builtin_unset.c
int						actualize_env_tab(t_data *data);
int						builtin_unset(t_command *command, t_data *data);
// initialize_last_word.c
int						initialize_last_word(t_data *data);
//env_tools.c
char					*get_env_value(char *key, t_data *data);
int						compare_env_key(t_env *env, char *key);
bool		key_not_found(t_data *data, char *key);
bool		value_not_found(t_data *data, char *key);

//path.c
int						set_path(t_data *data);

//parsing.c
bool					is_new_command(char *str, int index);
int						parse_line(char *line, t_data *mini);
//static int				set_last_and_previous_word(t_mini *mini);
void				manage_line(char *line, t_data *mini);

//command.c
//static char				*create_new_command_str_fmt(char *old_str);
char					*create_new_command_str(char *line);
static t_command		*create_new_command(char *line);
int						add_new_command(char *line, t_data *mini);

//check_cmd.c
bool					inside_quote(char *str, int index);

//loop.c
void			launching_loop(t_data *mini);

// builtin_pwd.c
int     builtin_pwd(t_data *data, t_command *cmd);

// builtin_echo.c
int     builtin_echo(t_data *data, t_command *cmd);

#endif