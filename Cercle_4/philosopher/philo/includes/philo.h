/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:29:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/23 18:52:47 by bsavinel         ###   ########.fr       */
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
	right = 0,
	left = 1
}	t_first_hand;

typedef enum e_status
{
	eating = 0,
	sleeping = 1,
	thinking = 2
}	t_status;

/*
 *	Structure
 */

typedef struct s_philo
{
	int				name;
	t_first_hand	first_hand;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	t_status		status;
	struct s_global	*global;
	int				date_of_death;
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
	int				death;
	t_info			info;
	pthread_mutex_t	*tab_fork;
	suseconds_t		time_start;
	pthread_t		*tab_ptread;
	t_philo			*tab_philo;
}	t_global;

/*
 *	end_tools.c
 */

int				destruc_fork(t_global *global, int nb_fork);
int				fusion_philo(t_global *global, int nb_philo);

/*
 *	end.c
 */

int				good_end(t_global *global);
int				exit_no_tab_philo(t_global *global);
int				exit_no_arg(void);
int				exit_time_or_mutex(void);

/*
 *	init_global.c
 */

int				check_av(int ac, char **av);
t_info			feed_info(int ac, char **av);
pthread_mutex_t	*creation_tab_fork(t_global *global);
t_global		*create_global(int ac, char **av);

/*
 *	init_tab_philo.c
 */

int				creation_tab_philo(t_global *global);

/*
 *	philo_mini_utils.c
 */

int				ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_isspace(char c);
int				give_utime(void);

/*
 *	philo_utils.c
 */

int				check_int(char *str);
long int		ft_atol(const char *nptr);

/*

 *
 *	routine.c
 *

void			create_identity(t_global *personnel);
void			*start_routine(void *pesonel);
int				eat_and_sleep(t_global *personnel);


int			init_global(t_global *global, int ac, char **av);
int			creation_tab_fork(t_global *global);
int			set_time(t_global *global);
int 		create_philo(t_global *global, t_global copie, int i);
int			launch_philo(t_global *global, t_global copie);*/

#endif