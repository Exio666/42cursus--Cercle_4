/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:50:28 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/23 13:15:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_identity(t_global *personnel)
{
	if (personnel->identity.name % 2 == 0)
		personnel->identity.first_hand = right;
	else
		personnel->identity.first_hand = left;
	personnel->identity.forks_right = personnel->identity.name;
	personnel->identity.forks_left = personnel->identity.name + 1;
	if (personnel->identity.name == personnel->info.nb_philo - 1)
		personnel->identity.forks_left = 0;
}

int	eat_and_sleep(t_global *personnel)
{
	int	counter;

	counter = 0;
	while (*personnel->death == 0 && (counter < personnel->info.number_eat || personnel->info.number_eat == -1))
	{
		if (*personnel->death == 0 && (counter < personnel->info.number_eat || personnel->info.number_eat == -1) && !(counter == 0 && personnel->identity.first_hand == left))
			counter = 0;
		if (*personnel->death == 0 && (counter < personnel->info.number_eat || personnel->info.number_eat == -1))
			counter = 0;
		counter++;
	}
	return (counter);
}

void	*start_routine(void *structure)
{
	int 		counter;
	t_global	*personnel;

	personnel = structure;
	printf("name : %i\n", personnel->identity.name);
	create_identity(personnel);
	counter = eat_and_sleep(personnel);
	/*TODO mettre un mutex*/
	if (counter == personnel->info.number_eat && *personnel->death != -1)
		*personnel->death += 1;
	return (NULL);	
}
