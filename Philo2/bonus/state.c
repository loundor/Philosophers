/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:32 by stissera          #+#    #+#             */
/*   Updated: 2022/05/31 00:22:33 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	takefork(t_philo *philo)
{
	int	sem;

	sem = 0;
	if (philo->config->end)
		return (1);
	while (sem++ < 2)
	{
		sem_wait(philo->config->sema);
		print_status(philo->id, philo, FORK_MSG);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	int	sem;

	philo->time = gettime();
	if (philo->need_eat && !philo->config->end)
	{
		print_status(philo->id, philo, EAT_MSG);
		usleep(philo->config->time_to_eat * 1000);
		philo->need_eat--;
	}
	sem = 0;
	while (sem++ < 2)
		sem_post(philo->config->sema);
	if (philo->config->end)
		return (1);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (philo->need_eat && !philo->config->end)
	{
		print_status(philo->id, philo, SLEEP_MSG);
		usleep(philo->config->time_to_sleep * 1000);
	}
	else
		return (1);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (philo->need_eat && !philo->config->end)
		print_status(philo->id, philo, THINK_MSG);
	else
		return (1);
	return (0);
}
