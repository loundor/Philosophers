/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:31:11 by stissera          #+#    #+#             */
/*   Updated: 2022/05/02 23:19:11 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	create_philo(t_config *config, t_master *master)
{
	t_philo	*philo;
	t_philo	*philof;
	int		i;

	i = 0;
	while (++i <= config->number_of_philosophers)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (0);
		philo->id = i;
		philo->life = config->time_to_die;
		philo->eated = 0;
		if (pthread_mutex_init(&philo->fork, NULL))
			return (0);
		philo->state = 0;
		if (i > 1)
		{
			philo->right = master->last;
			philo->left = master->first;
			master->last->left = philo;
			philof->right = philo;
		}
		else
		{
			philo->right = philo;
			philo->left = philo;
			master->first = philo;
			philof = philo;
		}
		master->last = philo;
		philo == NULL;
		printf("Thread %d created!\n", i);
	}
	return (i);
}

void	free_philo(t_config *config, t_master *master)
{
	t_philo	*bak;
	int		i;

	i = config->number_of_philosophers + 1; // Le premier philo a l id 1... create philo commemce a zero.
	while (--i > 0)
	{
		bak = master->last;
		pthread_mutex_destroy(&master->last->fork);
		if (i != 0)
			master->last = master->last->right;
		free(bak);
		printf("Thread %d free\n", i);
	}
	master->first = NULL;
	master->last = NULL;
}
