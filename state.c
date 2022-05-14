/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:32 by stissera          #+#    #+#             */
/*   Updated: 2022/05/14 20:04:42 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->left->fork);
	if (*philo->state != DEAD)
	{
		philo->life = gettime();
		printf("║%11ld ║%11ld ║ %-19s║▒%d\n", gettime() - philo->time, philo->id,
			"🥢", philo->eated + 1);
		printf("║%11ld ║%11ld ║  %-18s║▒\n", gettime() - philo->time, philo->id,
			"🥣");
		usleep(philo->config->time_to_eat);
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
