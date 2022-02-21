/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:38:07 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/15 13:44:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

/*
 *  list struct
 */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
 *  chain struct
 */

typedef struct s_chain
{
	int				content;
	struct s_chain	*next;
	struct s_chain	*back;
}	t_chain;

/*
 *  Fonction Part 1
 */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

/*
 *  Fonction Part 2
 */

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*
 *  Fonction Bonus part
 */

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *elem);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *elem);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
 *	Fonction Chain
 */

t_chain		*ft_chainlast(t_chain *lst);
t_chain		*ft_chainmap(t_chain *lst, int (*f)(int));
t_chain		*ft_chainnew(int content);
int			ft_chainsize(t_chain *lst);
void		ft_chainadd_back(t_chain **alst, t_chain *new);
void		ft_chainadd_front(t_chain **alst, t_chain *new);
void		ft_chainclear(t_chain **lst);
void		ft_chaindelone(t_chain *lst);
void		ft_chainiter(t_chain *lst, int (*f)(int));

/*
 *	autre
 */

int			ft_putnbr_unsign_base(unsigned long long int nbr, char *base);
int			ft_putnbr_base(long long int nbr, char *base);
int			ft_len_nbr(long long int n, char *base);
int			ft_len_nbr_unsign(unsigned long long int n, char *base);
int			ft_putchar_unsigned_fd(unsigned char c, int fd);
int			ft_putstr_unsigned_fd(unsigned char *s, int fd);
size_t		ft_unsigned_strlen(const unsigned char *s);
int			ft_abs(int a);
long int	ft_atoi_long(const char *nptr);

#endif
