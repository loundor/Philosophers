/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:32 by stissera          #+#    #+#             */
/*   Updated: 2022/05/15 12:19:03 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	eating(t_philo *philo)
{
	if (*philo->state == DEAD)
		return ;
	pthread_mutex_lock(&philo->fork);
	printf("║%11ld ║%11ld ║ %-19s║▒\n", gettime() - philo->time, philo->id,
		"🥢");
	if (*philo->state == DEAD)
	{
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	pthread_mutex_lock(&philo->left->fork);
	if (*philo->state != DEAD)
	{
		printf("║%11ld ║%11ld ║ %-19s║▒\n", gettime() - philo->time, philo->id,
			"🥢");
		printf("║%11ld ║%11ld ║  %-18s║▒\n", gettime() - philo->time, philo->id,
			"🥣");
		usleep(philo->config->time_to_eat);
		philo->life = gettime();
		philo->eated++;
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->left->fork);
	philo->status = SLEEP;
}

void	sleeping(t_philo *philo)
{
	if (*philo->state == DEAD
		|| philo->eated == philo->config->nbr_philo_must_eat)
		return ;
	printf("║%11ld ║%11ld ║    %-16s║▒\n", gettime() - philo->time,
		philo->id, "😴");
	usleep(philo->config->time_to_sleep);
	philo->status = THINK;
}

void	thinking(t_philo *philo)
{
	if (*philo->state == DEAD
		|| philo->eated == philo->config->nbr_philo_must_eat)
		return ;
	printf("║%11ld ║%11ld ║      %-14s║▒\n", gettime() - philo->time, philo->id,
		"🤔");
}
