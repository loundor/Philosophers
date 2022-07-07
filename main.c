/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/05/28 10:36:21 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_config		config;

	if (!arg_take(&config, argc, argv))
		return (0);
	if (!create_philo(&config))
		return (0);
	routine(&config);
	free_philo(&config);
	return (0);
}

int	routine(t_config *master)
{
	pthread_t	philo;
	size_t		i;

	i = 0;
	print_header(master);
	master->start = gettime();
	while (i < master->number_of_philosophers)
	{
		master->philosophers[i].time = gettime();
		if (pthread_create(&master->philosophers[i].action, NULL, &launch,
				&master->philosophers[i]))
			return (msg_error(THREAD_ERR));
		if (pthread_create(&philo, NULL, monitor, &master->philosophers[i]))
			return (msg_error(THREAD_ERR));
		pthread_detach(philo);
		i++;
	}
	i = 0;
	while (i < master->number_of_philosophers)
	{
		pthread_join(master->philosophers[i].action, NULL);
		i++;
	}
	print_bottom(master);
	return (0);
}

void	*launch(void *user)
{
	t_philo		*philo;

	philo = (t_philo *)user;
	if (philo->id % 2 == 0)
		usleep (philo->config->time_to_eat * 10);
	while (philo->need_eat != 0 && philo->config->end == 0)
	{
		takefork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	finish(philo);
	return (NULL);
}
