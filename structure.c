/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:31:11 by stissera          #+#    #+#             */
/*   Updated: 2022/05/28 10:43:30 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	create_philo(t_config *config)
{
	int		i;

	config->philosophers = malloc(sizeof(t_philo)
			* config->number_of_philosophers);
	if (!config->philosophers)
		return (msg_error(MALLOC_ERR));
	i = -1;
	pthread_mutex_init(&config->writing, NULL);
	pthread_mutex_init(&config->monitoring, NULL);
	config->end = 0;
	while (++i < config->number_of_philosophers)
	{
		config->philosophers[i].id = i;
		config->philosophers[i].need_eat = config->nbr_philo_must_eat;
		config->philosophers[i].config = config;
		if (pthread_mutex_init(&config->philosophers[i].lfork, NULL))
			return (0);
		if (i > 0)
			config->philosophers[i].rfork = &config->philosophers[i - 1].lfork;
	}
	config->philosophers[0].rfork = \
				&config->philosophers[config->number_of_philosophers - 1].lfork;
	return (i);
}

void	free_philo(t_config *config)
{
	int		i;

	i = config->number_of_philosophers;
	while (--i > 0)
		pthread_mutex_destroy(&config->philosophers[i].lfork);
	free(config->philosophers);
	config->philosophers = NULL;
}
