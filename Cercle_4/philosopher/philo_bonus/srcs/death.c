/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:35:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/02 16:49:52 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_death(t_philo *philo)
{
	int	condition;

	condition = 1;
	if (philo->global->death->__align != 0)
		condition = 0;
	return (condition);
}

void	modifier_death(t_philo *philo)
{
	printer_sem(philo, philo->global->print, philo->name, "died");
	sem_post(philo->global->death);
}
