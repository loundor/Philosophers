/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/05/31 00:22:35 by stissera         ###   ########.fr       */
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
	while (i <= master->number_of_philosophers)
	{
		master->philosophers[i].id_pid = fork();
		master->philosophers[i].start_at = gettime();
		master->philosophers[i].time = master->philosophers[i].start_at;
		if (master->philosophers[i].id_pid == 0)
			launch(&master->philosophers[i]);
		else if (master->philosophers[i].id_pid < 0)
			return (msg_error(FORK_ERR));
		i++;
	}
	i = -1;
	while (++i <= master->number_of_philosophers)
		waitpid(master->philosophers[i].id_pid, NULL, 0);
	print_bottom(master);
	return (0);
}

void	*launch(void *user)
{
	t_philo		*philo;
	pthread_t	monitoring;

	philo = (t_philo *)user;
	pthread_create(&monitoring, NULL, &monitor, user);
	pthread_detach(monitoring);
	if (philo->id % 2 == 0)
		usleep (philo->config->time_to_eat * 10);
	while (philo->need_eat != 0 && philo->config->end == 0)
	{
		if (takefork(philo) || eating(philo)
			|| sleeping(philo) || thinking(philo))
			exit (0);
	}
	finish(philo);
	exit (0);
}
