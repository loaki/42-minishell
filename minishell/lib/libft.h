/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:47:51 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/10/12 01:55:18 by lulebugl         ###   ########.fr       */
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
size_t			ft_strlen(const char *str);
int				ft_strjoin(char **s1, char *s2);
void			ft_init(char *str);
int				ft_eof(char **line, char **str, char *buffer, int eof);
int				ft_find_nl(char *buffer);
int				ft_nl(char **line, char *str, int nl);
int				get_next_line(int fd, char **line);

void	        ft_putchar_fd(char c, int fd);
void	        ft_putstr_fd(char *s, int fd);
void	        ft_putnbr_fd(int n, int fd);

/*
**	list
*/
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);

#endif
