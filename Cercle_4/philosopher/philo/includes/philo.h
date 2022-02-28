/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:29:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/28 18:40:20 by bsavinel         ###   ########.fr       */
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

typedef struct s_info
{
	int			nb_philo;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			number_eat;
}	t_info;

typedef struct s_philo
{
	int				name;
	t_first_hand	first_hand;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_status		status;
	struct s_global	*global;
	size_t			date_of_death;
	t_info			info;
	int				number_of_eat;
}	t_philo;

typedef struct s_global
{
	pthread_mutex_t	mutt_death;
	pthread_mutex_t	mutt_print;
	int				death;
	t_info			info;
	pthread_mutex_t	*tab_fork;
	size_t			time_start;
	pthread_t		*tab_pthread;
	t_philo			*tab_philo;
}	t_global;

/*
 *	create_thread.c
 */

int				launch_philo(t_global *global);

/*
 *	death.c
 */

int				check_death(t_philo *philo, pthread_mutex_t *muttex);
int				check_death_global(t_global *global, pthread_mutex_t *muttex);
void			modifier_death(t_philo *philo, pthread_mutex_t *muttex,
					int value);

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
size_t			give_utime(void);
void			_usleep(size_t time);

/*
 *	philo_utils.c
 */

int				check_int(char *str);
long int		ft_atol(const char *nptr);
void			printer_mutex(t_philo *philo, pthread_mutex_t *muttex,
					int name, char *str);
int				check_death(t_philo *philo, pthread_mutex_t *muttex);
int				check_death_global(t_global *global, pthread_mutex_t *muttex);
void			modifier_death(t_philo *philo, pthread_mutex_t *muttex,
					int value);

/*
 *	routine.c
 */

void			*routine(void *structure);
void			start_eat(t_philo *philo);
void			start_sleep(t_philo *philo);

#endif