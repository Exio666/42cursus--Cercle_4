/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:31:34 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/22 19:55:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_philo(t_global *global, t_global copie, int i)
{
	int	err;

	err = pthread_create(&(global->philo[i]), NULL, &doSomeThing, &copie);
    return (err);
}

int	launch_philo(t_global *global, t_global copie)
{
	int	i;
	int err;
	
	i = 0;
	while (i < global->info.nb_philo)
	{
		err = create_philo(global, copie, i);
		if (err != 0)
			return (0);
		i++;
	}
	return (1);
}

int	creation_tab_fork(t_global *global)
{
	int	i;

	i = 0;
	global->tab_fork = malloc(sizeof(pthread_mutex_t *)
			* global->info.nb_philo);
	if (!global->tab_fork)
		return (0);
	global->death = malloc(sizeof(int));
	if (!global->death)
	{
		free(global->tab_fork);
		return (0);
	}
	global->death = 0;
	global->philo = malloc(sizeof(pthread_t *) * global->info.nb_philo);
	if (!global->tab_fork)
	{
		free(global->death);
		free(global->tab_fork);
		return (0);
	}
	while (i < global->info.nb_philo)
	{
		pthread_mutex_init(&global->tab_fork[i], NULL);
		i++;
	}
	return (1);
}

int	init_global(t_global *global, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (0);
	while (i < ac)
	{
		if (!check_int(av[i]))
			return (0);
		i++;
	}
	global->info.nb_philo = (int)atol(av[1]);
	global->info.time_to_die = (int)atol(av[2]);
	global->info.time_to_eat = (int)atol(av[3]);
	global->info.time_to_sleep = (int)atol(av[4]);
	if (ac == 6)
		global->info.number_eat = (int)atol(av[5]);
	else
		global->info.number_eat = -1;
	return (1);
}

int	set_time(t_global *global)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	global->time_start = time.tv_usec;
	return (1);
}
