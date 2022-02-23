/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/23 18:44:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_global	*global;

	global = create_global(ac, av);
	if (!global)
		return (exit_no_arg());
	if (!creation_tab_philo(global))
		return (exit_no_tab_philo(global));
	printf("Tout est ok ?????\n");
	good_end(global);
	printf("Tout est ok !!!!!\n");
	return (0);
}
