/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:35:29 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/01 15:57:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(char *str)
{
	int			len;
	int			i;
	long int	nb;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == '0' && i < len - 1)
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10 || len <= 0)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nb = ft_atol(str);
	if (nb < 0 || nb > 2147483647)
		return (0);
	return (1);
}

long int	ft_atol(const char *nptr)
{
	long int	neg;
	int			i;
	long int	nb;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	if (neg == -1)
		nb = -nb;
	return (nb);
}

void	printer_mutex(t_philo *philo, pthread_mutex_t *muttex,
			int name, char *str)
{
	pthread_mutex_lock(muttex);
	if (check_death(philo, &philo->global->mutt_death))
		printf("%05li %i %s\n", give_utime() - philo->start,
			name + 1, str);
	pthread_mutex_unlock(muttex);
}

void	take_fork(t_philo *philo)
{
	while (give_utime() < philo->date_of_death)
	{
		pthread_mutex_lock(&philo->fork_right->fork);
		if (philo->fork_right->take == 0)
		{
			philo->fork_right->take = 1;
			pthread_mutex_unlock(&philo->fork_right->fork);
			break ;
		}
		pthread_mutex_unlock(&philo->fork_right->fork);
	}
	printer_mutex(philo, &philo->global->mutt_print, philo->name, TAKE_FORK);
	while (give_utime() <= philo->date_of_death + 1)
	{
		pthread_mutex_lock(&philo->fork_left->fork);
		if (philo->fork_left->take == 0)
		{
			philo->fork_left->take = 1;
			pthread_mutex_unlock(&philo->fork_left->fork);
			break ;
		}
		pthread_mutex_unlock(&philo->fork_left->fork);
	}
	if (give_utime() > philo->date_of_death)
		modifier_death(philo, &philo->global->mutt_death, -1);
	printer_mutex(philo, &philo->global->mutt_print, philo->name, TAKE_FORK);
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_right->fork);
	philo->fork_right->take = 0;
	pthread_mutex_unlock(&philo->fork_right->fork);
	pthread_mutex_lock(&philo->fork_left->fork);
	philo->fork_left->take = 0;
	pthread_mutex_unlock(&philo->fork_left->fork);
}
