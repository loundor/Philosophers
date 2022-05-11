/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/05/11 18:43:12 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_config		config;
	t_master		master;
	int				setting;

	arg_take(&config, argc, argv);
	setting = create_philo(&config, &master);
	if (!setting)
	{
		printf("Bad setting on arguments!\n");
		return (0);
	}
	master.config = &config;
	master.dead = 0;
	routine(&master);
	free_philo(&config, &master);
	return (0);
}

void	routine(t_master *master)
{
	t_philo		*need_eat;
	pthread_t	monitoring;
	size_t		i;

	master->start = gettime();
	pthread_create(&monitoring, NULL, &monitor, master);
	print_header();
 	i=0;
	while (++i <= master->config->number_of_philosophers)
	{
		pthread_create(&master->first->action, NULL, &launch, master->first);
		master->first = master->first->right;
	}
	pthread_join(monitoring, NULL);
	print_bottom();
}

void	*launch(void *user)
{
	t_philo		*philo;

	philo = (t_philo *)user;
	usleep(100);
	while (philo->eated <= philo->config->nbrt_philo_must_eat
		|| philo->config->nbrt_philo_must_eat == -1 && philo->state != DEAD)
	{
		if (philo->state == THINKING && philo->inaction == 0)
		{
			philo->inaction = 1;
			pthread_create(&philo->action, NULL, &eating, philo);
		}
		else if (philo->state == SLEEPING && philo->inaction == 0)
		{
			philo->inaction = 1;
			pthread_create(&philo->action, NULL, &sleeping, philo);
			pthread_join(philo->action, NULL);
			pthread_create(&philo->action, NULL, &thinking, philo);
		}
	}
	printf("║           Philosopher %ld as finish!           ║▒\n", philo->id);
}

void	print_header(void)
{
	printf("╔════════════╦════════════╦════════════════════╗\n");
	printf("║   Time     ║   Philo    ║        Event       ║\n");
	printf("╠════════════╬════════════╬════════════════════╣▒\n");
}

void	print_bottom(void)
{
	printf("╚════════════╩════════════╩════════════════════╝▒\n");
	printf("  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
}
