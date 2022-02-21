/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:29:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/21 17:48:20 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>

/*
 *	Structure
 */

typedef struct s_philo
{
	int	name;
	int forks_left;
	int forks_right;
}	t_philo;

/*
 *	philo_utils.c
 */

int			check_int(char *str);
int			ft_isspace(char c);
int			ft_atoi(const char *nptr);
long int	ft_atoi_long(const char *nptr);
#endif