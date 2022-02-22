/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/22 19:52:19 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_global	global;

	if (!init_global(&global, ac, av))
		return (exit_no_arg());
	else
	{
		if (set_time(&global) && creation_tab_fork(&global))
		{
			lauch_philo(global);
			while (*global.death == 0)
				;
			return (good_end(&global));
		}
		else
			return (exit_time_or_mutex());
	}
}
