/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:47:51 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/10/12 07:33:34 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 26
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 4000
# endif

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//get_next_line
char			*ft_strdup(char *src);
int				ft_substr(char *s, unsigned int start, size_t len);
int				ft_strjoin(char **s1, char *s2);
void			ft_init(char *str);
int				ft_eof(char **line, char **str, char *buffer, int eof);
int				ft_find_nl(char *buffer);
int				ft_nl(char **line, char *str, int nl);
int				get_next_line(int fd, char **line);

void	        ft_putchar_fd(char c, int fd);
void	        ft_putstr_fd(char *s, int fd);
void			ft_putstr_fd_and_color(char *s, int fd, char *color);
void	        ft_putnbr_fd(int n, int fd);

/*
** Utils
*/
size_t			ft_strlen(const char *str);
char			*ft_str_join(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);

/*
**	list
*/
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstremove_if(t_list **begin_list, void *data_ref,
										int (*cmp)(), void (*clean_fct)());

#endif
