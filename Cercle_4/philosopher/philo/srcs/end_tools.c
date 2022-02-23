/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:24:38 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/23 18:57:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fusion_philo(t_global *global, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_join(global->tab_ptread[i], NULL);
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
	return (1);
}
