/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:04:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/24 12:18:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_philo(t_global *global)
{
	int	i;
	int	err;

	i = 0;
	global->tab_pthread = malloc(sizeof(pthread_t) * global->info.nb_philo);
	if (!global->tab_pthread)
		return (-1);
	while (i < global->info.nb_philo)
	{
		usleep(1);
		err = pthread_create(&global->tab_pthread[i], NULL, &routine,
				&global->tab_philo[i]);
		if (err != 0)
			return (i);
		i++;
	}
	return (0);
}
