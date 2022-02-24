/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:35:29 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/24 12:10:18 by bsavinel         ###   ########.fr       */
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

void	printer_mutex(pthread_mutex_t *muttex, int name, char *str)
{
	pthread_mutex_lock(muttex);
	printf("%i %i %s\n", give_utime(), name, str);
	pthread_mutex_unlock(muttex);
}

int	check_death(t_philo *philo, pthread_mutex_t *muttex)
{
	int	condition;

	condition = 1;
	pthread_mutex_lock(muttex);
	if (philo->global->death == -1)
		condition = 0;
	pthread_mutex_unlock(muttex);
	return (condition);
}

int	check_death_global(t_global *global, pthread_mutex_t *muttex)
{
	int	condition;

	condition = 1;
	pthread_mutex_lock(muttex);
	if (global->death == -1)
		condition = 0;
	pthread_mutex_unlock(muttex);
	return (condition);
}

void	modifier_death(t_philo *philo, pthread_mutex_t *muttex, int value)
{
	pthread_mutex_lock(muttex);
	if (value == 1 && philo->global->death != -1)
		philo->global->death += 1;
	if (value == -1)
		philo->global->death = -1;
	pthread_mutex_unlock(muttex);
}
