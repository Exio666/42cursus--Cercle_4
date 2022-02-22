/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:29:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/22 19:38:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>

# define LIST_OF_ARG "./philo time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]"

/*
 *	Enumeration
 */

typedef enum e_first_hand
{
	left = 0,
	right = 1
}	t_first_hand;

/*
 *	Structure
 */

typedef struct s_philo
{
	int				name;
	t_first_hand	first_hand;
	int				forks_left;
	int				forks_right;
}	t_philo;

typedef struct s_info
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_eat;
}	t_info;

typedef struct s_global
{
	t_info			info;
	int				*death;
	pthread_mutex_t	*tab_fork;
	suseconds_t		time_start;
	pthread_t		*philo;
}	t_global;

/*
 *	philo_utils.c
 */

int			check_int(char *str);
int			ft_isspace(char c);
long int	ft_atol(const char *nptr);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);

/*
 *	start.c
 */

int			init_global(t_global *global, int ac, char **av);
int			creation_tab_fork(t_global *global);
int			set_time(t_global *global);

/*
 *	end.c
 */

int			exit_no_arg(void);
int			exit_time_or_mutex(void);
void		destruc_fork(t_global *global, int nb_fork);

#endif