/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:32 by stissera          #+#    #+#             */
/*   Updated: 2022/05/28 10:46:09 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	takefork(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	print_status(philo->id, philo, FORK_MSG);
	if (philo->config->number_of_philosophers > 1)
	{
		pthread_mutex_lock(&philo->lfork);
		if (philo->config->end == 0)
			print_status(philo->id, philo, FORK_MSG);
	}
	else
		usleep(philo->config->time_to_die * 1001);
}

void	eating(t_philo *philo)
{
	philo->time = gettime();
	if (philo->need_eat != 0)
	{
		print_status(philo->id, philo, EAT_MSG);
		usleep(philo->config->time_to_eat * 1000);
		philo->need_eat--;
	}
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	sleeping(t_philo *philo)
{
	if (philo->need_eat != 0)
	{
		print_status(philo->id, philo, SLEEP_MSG);
		usleep(philo->config->time_to_sleep * 1000);
	}
}

void	thinking(t_philo *philo)
{
	if (philo->need_eat != 0)
	{
		print_status(philo->id, philo, THINK_MSG);
	}
}

