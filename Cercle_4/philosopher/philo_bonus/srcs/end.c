/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:00:41 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/02 17:12:34 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	good_end(t_global *global)
{	
	sem_close(global->death);
	sem_close(global->print);
	sem_close(global->fork);
	sem_close(global->look_fork);
	sem_close(global->sem_start);
	return (1);
}

int	exit_no_arg(void)
{
	printf("Argument is not valiable\n");
	printf("Please make sur you have lunch with : %s\n", LIST_OF_ARG);
	return (0);
}
