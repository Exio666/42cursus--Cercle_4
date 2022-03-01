/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:39:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/01 10:40:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creation_tab_philo(t_global *global)
{
	int	i;
	int	nb_philo;

	i = 0;
	nb_philo = global->info.nb_philo;
	global->tab_philo = malloc(sizeof(t_philo) * nb_philo);
	if (!global->tab_philo)
		return (0);
	memset(global->tab_philo, 0, sizeof(t_philo) * nb_philo);
	while (i < nb_philo)
	{
		global->tab_philo[i].name = i;
		global->tab_philo[i].fork_right = &global->tab_fork[i];
		global->tab_philo[i].fork_left = &global->tab_fork[(i + 1) % nb_philo];
		global->tab_philo[i].global = global;
		global->tab_philo[i].date_of_death = give_utime()
			+ global->info.time_to_die;
		global->tab_philo[i].info = global->info;
		global->tab_philo[i].number_of_eat = 0;
		i++;
	}
	return (1);
}
