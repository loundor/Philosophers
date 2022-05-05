/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:56:12 by stissera          #+#    #+#             */
/*   Updated: 2022/05/05 15:10:40 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// DEBUG ZONE **************************
/* 	i = 0;
	master = first;
	while (++i <= config->number_of_philosophers)
	{
		printf("Life time of %ld start at %ld.%6d\n", master->first->left->life,
			master->first->left->start.tv_sec,
			master->first->left->start.tv_usec);
		master->first = master->first->left;
	} */

long	get_id_time(t_philo *philo)
{
	long	time;

	gettimeofday(&philo->start, NULL);
	time = (((philo->start.tv_sec % 10000) * 1000000)
			+ philo->start.tv_usec);
	return (time);
}

void	gettime(t_master *first, t_config *config)
{
	int			i;
	t_master	*master;

	master = first;
	i = 0;
	while (++i <= config->number_of_philosophers)
	{
		gettimeofday(&master->first->start, NULL);
		master->first->life = (((master->first->start.tv_sec % 10000) * 1000000)
				+ master->first->start.tv_usec);
		master->first = master->first->left;
	}
}
