/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:31:11 by stissera          #+#    #+#             */
/*   Updated: 2022/06/04 21:57:42 by stissera         ###   ########.fr       */
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
	sem_unlink("semaphore");
	sem_unlink("writing");
	config->sema = sem_open("semaphore", O_CREAT | O_EXCL,
			0600, config->number_of_philosophers);
	config->writing = sem_open("writing", O_CREAT | O_EXCL,
			0600, 1);
	config->end = 0;
	while (++i < config->number_of_philosophers)
	{
		config->philosophers[i].id = i;
		config->philosophers[i].need_eat = config->nbr_philo_must_eat;
		config->philosophers[i].config = config;
	}
	return (i);
}

void	free_philo(t_config *config)
{
	size_t	i;

	i = -1;
	sem_unlink("writing");
	sem_unlink("waitend");
	while (++i < config->number_of_philosophers)
	{
		if (config->philosophers[i].id_pid)
			kill(config->philosophers[i].id_pid, 9);
	}
	sem_close(config->sema);
	sem_close(config->writing);
	free(config->philosophers);
	config->philosophers = NULL;
}
