/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:04:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/02 18:49:39 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	launch_philo(t_global *global)
{
	int			i;
	pid_t		pid;
	t_global	launcher;

	i = 0;
	launcher = *global;
	while (i < global->info.nb_philo)
	{
		pid = fork();
		if (pid == 0)
		{
			launcher.philo.name = i;
			routine(launcher);
			return (0);
		}
		i++;
	}
	return (1);
}
