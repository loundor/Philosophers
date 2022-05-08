/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:36:32 by stissera          #+#    #+#             */
/*   Updated: 2022/05/07 18:25:43 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	eating(t_philo *philo, t_config *config)
{
	philo->state = EATING;
	pthread_mutex_lock(&philo->left->fork);
	pthread_mutex_lock(&philo->right->fork);
	printf("║%11ld║%11ld║%-20s║▒\n", ((philo->start.tv_sec % 10000)
			* 1000000) + philo->start.tv_usec, philo->id, " has taken a fork.");
	printf("║%11ld║%11ld║%-20s║▒\n", ((philo->start.tv_sec % 10000)
			* 1000000) + philo->start.tv_usec, philo->id, " is eating.");
	//printf("%ld %d has taken a fork.\n", get_id_time(philo));
	//printf("%ld %d is eating.\n", get_id_time(philo));
	usleep(config->time_to_eat);
	gettimeofday(&philo->start, NULL);
	philo->life = (((philo->start.tv_sec % 10000) * 1000000)
			+ philo->start.tv_usec);
	pthread_mutex_unlock(&philo->left->fork);
	pthread_mutex_unlock(&philo->right->fork);
}

void	sleeping(t_philo *philo, t_config *config)
{
	philo->state = SLEEPING;
	printf("║%11ld║%11ld║%-20s║▒\n", ((philo->start.tv_sec % 10000)
			* 1000000) + philo->start.tv_usec, philo->id, " is slepping.");
	//printf("%ld %d is slepping.\n", get_id_time(philo));
	usleep(config->time_to_eat);
}

void	thinking(t_philo *philo, t_config *config)
{
	philo->state = THINKING;
	printf("║%11ld║%11ld║%-20s║▒\n", ((philo->start.tv_sec % 10000)
			* 1000000) + philo->start.tv_usec, philo->id, " is thinking.");
	//printf("%ld %d is thinking.\n", get_id_time(philo));
}
