/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:31:11 by stissera          #+#    #+#             */
/*   Updated: 2022/05/14 19:16:05 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	push_next_philo(t_philo *philo, t_philo *philof, t_master *master)
{
	philo->right = master->last;
	philo->left = master->first;
	master->last->left = philo;
	philof->right = philo;
}

t_philo	*push_first_philo(t_philo *philo, t_master *master)
{
	philo->right = philo;
	philo->left = philo;
	master->first = philo;
	return (philo);
}

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
		philo->eated = 0;
		philo->state = &master->dead;
		philo->time = gettime();
		philo->config = config;
		philo->life = gettime();
		if (pthread_mutex_init(&philo->fork, NULL))
			return (0);
		if (i > 1)
			push_next_philo(philo, philof, master);
		else
			philof = push_first_philo(philo, master);
		master->last = philo;
		philo = 0; // Maybe can remove...
	}
	return (i);
}

void	free_philo(t_config *config, t_master *master)
{
	t_philo	*bak;
	int		i;

	i = config->number_of_philosophers;
	while (i > 0)
	{
		bak = master->last;
		pthread_mutex_destroy(&master->last->fork);
		if (i != 0)
			master->last = master->last->right;
		free(bak);
		i--;
	}
	master->first = NULL;
	master->last = NULL;
}
