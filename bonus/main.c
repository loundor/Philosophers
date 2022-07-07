/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/07/07 17:55:07 by stissera         ###   ########.fr       */
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
	kill_philo(&config);
	sem_post(config.writing);
	print_bottom(&config);
	free_philo(&config);
	exit (0);
}

int	routine(t_config *master)
{
	pthread_t	philo;
	size_t		i;
	int			good;

	i = 0;
	print_header(master);
	master->start = gettime();
	while (i <= master->number_of_philosophers)
	{
		master->philosophers[i].id_pid = fork();
		master->philosophers[i].start_at = master->start;
		master->philosophers[i].time = master->philosophers[i].start_at;
		if (master->philosophers[i].id_pid == 0)
			launch(&master->philosophers[i]);
		else if (master->philosophers[i].id_pid < 0)
			return (msg_error(FORK_ERR));
		i++;
	}
	i = 0;
	while (i++ < master->number_of_philosophers)
		sem_wait(master->deadphilo);
	//sem_post(master->writing);
	return (0);
}

int	launch(t_philo *philo)
{
	pthread_t	monitoring;

	sem_wait(philo->config->deadphilo);
	if (philo->id % 2 == 0)
		usleep (philo->config->time_to_eat * 10);
	pthread_create(&monitoring, NULL, monitor, philo);
	pthread_detach(monitoring);
	while (philo->need_eat && is_dead((int)philo->config->end))
	{
		if (takefork(philo) || eating(philo)
			|| sleeping(philo) || thinking(philo))
			break ;
	}
	if (!philo->need_eat)
		finish(philo);
	return (0);
}
