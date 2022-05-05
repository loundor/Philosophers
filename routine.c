/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:56:12 by stissera          #+#    #+#             */
/*   Updated: 2022/05/03 00:56:45 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_philo	*get_id_mintime(t_master *master)
{
	t_philo			*id;
	unsigned long	time;

	id = master->first;
	time = (master->first->start.tv_sec % 10 * 1000000)
		+ master->first->start.tv_usec;
	master->first = master->first->left;
	while (master->first->id != id)
	{
		if (time < ((master->first->start.tv_sec % 10 * 1000000)
				+ master->first->start.tv_usec)) // And may be state is not eating or thinking..
		{
			id = master->first;
			time = (master->first->start.tv_sec % 10 * 1000000)
				+ master->first->start.tv_usec;
		}
		master->first = master->first->left;
	}
	return (id);
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
		master->first = master->first->left;
	}

// DEBUG ZONE **************************
	i = 0;
	master = first;
	while (++i <= config->number_of_philosophers)
	{
		printf("Life time of %ld start at %ld.%6ld\n", master->first->left->id,
			master->first->left->start.tv_sec,
			master->first->left->start.tv_usec);
		master->first = master->first->left;
	}
}
