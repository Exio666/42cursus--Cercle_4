/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:04:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/23 19:17:12 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void *pointeur)
{
	t_philo *philo;

	philo = pointeur;
	printf("je suis le %i philosophe\n", philo->name);
	return (NULL);
}

int	launch_philo(t_global *global)
{
	int	i;
	int err;
	
	i = 0;
	global->tab_pthread = malloc(sizeof(pthread_t) * global->info.nb_philo);
	if (!global->tab_pthread)
		return (-1);
	while (i < global->info.nb_philo)
	{
		err = pthread_create(&global->tab_pthread[i], NULL, &test,
			&global->tab_philo[i]);
		if (err != 0)
			return (i);
		i++;
	}
	return (0);
}