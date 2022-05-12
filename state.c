/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:32 by stissera          #+#    #+#             */
/*   Updated: 2022/05/11 20:34:12 by stissera         ###   ########.fr       */
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
		" has taken a fork.", philo->eated + 1);
	printf("║%11ld ║%11ld ║%-20s║▒\n", gettime() - philo->time, philo->id,
		" is eating.");
	usleep(philo->config->time_to_eat);
	philo->life = gettime();
	philo->eated++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->left->fork);
	philo->inaction = 0;
	philo->state = SLEEPING;
}

void	*sleeping(void *need_sleep)
{
	t_philo	*philo;

	philo = (t_philo *)need_sleep;
	philo->state = SLEEPING;
	pthread_join(philo->action, NULL);
	printf("║%11ld ║%11ld ║%-20s║▒\n", gettime() - philo->time,
		philo->id, " is slepping.");
	usleep(philo->config->time_to_sleep);
}

void	*thinking(void *thing)
{
	t_philo	*philo;

	philo = (t_philo *)thing;
	philo->state = THINKING;
	printf("║%11ld ║%11ld ║%-20s║▒\n", gettime() - philo->time, philo->id,
		" is thinking.");
	philo->inaction = 0;
}
