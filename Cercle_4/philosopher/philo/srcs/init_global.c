/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:31:34 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/24 09:48:46 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_av(int ac, char **av)
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
	return (1);
}

t_info	feed_info(int ac, char **av)
{
	t_info	info;

	info.nb_philo = (int)atol(av[1]);
	info.time_to_die = (int)atol(av[2]);
	info.time_to_eat = (int)atol(av[3]);
	info.time_to_sleep = (int)atol(av[4]);
	if (ac == 6)
		info.number_eat = (int)atol(av[5]);
	else
		info.number_eat = -1;
	return (info);
}

pthread_mutex_t	*creation_tab_fork(t_global *global)
{
	pthread_mutex_t	*tab_fork;
	int				i;

	i = 0;
	tab_fork = malloc(sizeof(pthread_mutex_t) * global->info.nb_philo);
	if (!tab_fork)
		return (NULL);
	while (i < global->info.nb_philo)
	{
		pthread_mutex_init(&tab_fork[i], NULL);
		i++;
	}
	return (tab_fork);
}

t_global	*create_global(int ac, char **av)
{
	t_global	*new;

	if (!check_av(ac, av))
		return (NULL);
	new = malloc(sizeof(t_global));
	if (!new)
		return (NULL);
	memset(new, 0, sizeof(t_global));
	new->death = 0;
	new->info = feed_info(ac, av);
	new->tab_fork = creation_tab_fork(new);
	if (!new->tab_fork)
	{
		free(new);
		return (NULL);
	}
	pthread_mutex_init(&new->mutt_print, NULL);
	pthread_mutex_init(&new->mutt_death, NULL);
	new->time_start = give_utime();
	return (new);
}

/*
int create_philo(t_global *global, t_global copie, int i)
{
	int		err;
	void	*ptr;

	copie.identity.name = i;
	ptr = malloc(sizeof(t_global *));
	ptr = &copie;
	err = pthread_create(&global->philo[i], NULL, &start_routine, &ptr);
	return (err);
}

int	launch_philo(t_global *global, t_global copie)
{
	int	i;
	int err;
	
	i = 0;
	while (i < global->info.nb_philo)
	{
		copie.identity.name = i;
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
	global->tab_fork = malloc(sizeof(pthread_mutex_t)
			* global->info.nb_philo);
	if (!global->tab_fork)
		return (0);
	global->death = malloc(sizeof(int));
	if (!global->death)
	{
		free(global->tab_fork);
		return (0);
	}
	*global->death = 0;
	global->philo = malloc(sizeof(pthread_t) * global->info.nb_philo);
	if (!global->philo)
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
*/