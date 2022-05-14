/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:32 by stissera          #+#    #+#             */
/*   Updated: 2022/05/14 16:21:09 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*eating(void *need_eat)
{
	t_philo	*philo;

	philo = (t_philo *)need_eat;
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->left->fork);
	philo->state = EATING;
	printf("║%11ld ║%11ld ║%-20s║▒%d\n", gettime() - philo->time, philo->id,
		" 🥢", philo->eated + 1);
	printf("║%11ld ║%11ld ║%-20s║▒\n", gettime() - philo->time, philo->id,
		" 🥣");
	usleep(philo->config->time_to_eat);
	philo->life = gettime();
	philo->eated++;
	if (philo->state != DEAD)
		philo->state = SLEEPING;
	philo->inaction = 0;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->left->fork);
	return (NULL);
}

void	*sleeping(void *need_sleep)
{
	t_philo	*philo;

	philo = (t_philo *)need_sleep;
	if (philo->state == DEAD)
		return (NULL);
	philo->state = SLEEPING;
	pthread_join(philo->action, NULL);
	printf("║%11ld ║%11ld ║%-20s║▒\n", gettime() - philo->time,
		philo->id, " 😴");
	usleep(philo->config->time_to_sleep);
	return (NULL);
}

void	*thinking(void *thing)
{
	t_philo	*philo;

	philo = (t_philo *)thing;
	if (philo->state == DEAD)
		return (NULL);
	philo->state = THINKING;
	printf("║%11ld ║%11ld ║%-20s║▒\n", gettime() - philo->time, philo->id,
		" 🤔");
	philo->inaction = 0;
	return (NULL);
}
