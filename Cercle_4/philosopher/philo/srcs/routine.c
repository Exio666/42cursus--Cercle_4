/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:50:28 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/24 12:08:36 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sleep(t_philo *philo)
{
	printer_mutex(&philo->global->mutt_print, philo->name, "is sleeping");
	usleep(philo->info.time_to_sleep);
	printer_mutex(&philo->global->mutt_print, philo->name, "is thinking");
	usleep(1);
	start_eat(philo);
}

void	start_eat(t_philo *philo)
{
	if (give_utime() > philo->date_of_death)
		modifier_death(philo, &philo->global->mutt_death, -1);
	pthread_mutex_lock(philo->fork_right);
	printer_mutex(&philo->global->mutt_print, philo->name, "has  taken a fork");
	pthread_mutex_lock(philo->fork_left);
	printer_mutex(&philo->global->mutt_print, philo->name, "has  taken a fork");
	if (give_utime() > philo->date_of_death)
		modifier_death(philo, &philo->global->mutt_death, -1);
	philo->status = eating;
	if (check_death(philo, &philo->global->mutt_death))
	{
		printer_mutex(&philo->global->mutt_print, philo->name, "is eating");
		usleep(philo->info.time_to_eat);
	}
	if (give_utime() > philo->date_of_death)
	{
		printer_mutex(&philo->global->mutt_print, philo->name, "is dead");
		modifier_death(philo, &philo->global->mutt_death, -1);
	}
	else
	{
		philo->number_of_eat += 1;
		philo->date_of_death = give_utime() + philo->info.time_to_die;
	}
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	if (check_death(philo, &philo->global->mutt_death) && philo->number_of_eat != philo->info.number_eat)
		start_sleep(philo);
}

void	*routine(void *structure)
{
	t_philo	*philo;

	philo = structure;
	start_eat(philo);
	return (NULL);
}
