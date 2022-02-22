/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:00:41 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/22 19:59:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	good_end(t_global *global)
{
	fusion_philo(global, global->info.nb_philo);
	destruc_fork(global, global->info.nb_philo);
}

int	fusion_philo(t_global *global, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (1);
}

int	destruc_fork(t_global *global, int nb_fork)
{
	int	i;

	i = 0;
	while (i < nb_fork)
	{
		pthread_mutex_destroy(&global->tab_fork[i]);
		i++;
	}
	free(global->tab_fork);
	free(global->death);
	return (1);
}

int	exit_no_arg(void)
{
	printf("Argument is not valiable\n");
	printf("Please make sur you have lunch with : %s\n", LIST_OF_ARG);
	return (0);
}

int	exit_time_or_mutex(void)
{
	printf("Probleme with the time or one malloc fail");
	return (0);
}
