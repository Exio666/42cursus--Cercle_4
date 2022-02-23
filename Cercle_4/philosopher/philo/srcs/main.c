/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/23 19:12:19 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_global	*global;
	int			err;

	global = create_global(ac, av);
	if (!global)
		return (exit_no_arg());
	if (!creation_tab_philo(global))
		return (exit_no_tab_philo(global));
	err = launch_philo(global);
	if (err)
		return (0);
	good_end(global);
	return (0);
}
