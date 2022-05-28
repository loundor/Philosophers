/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/05/23 21:50:46 by stissera         ###   ########.fr       */
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
	master.finish = 0;
	master.dead = THINK;
	routine(&master);
	free_philo(&config, &master);
	return (0);
}

void	routine(t_master *master)
{
	t_philo		*need_eat;
	pthread_t	monitoring;
	pthread_t	all_eated;
	size_t		i;
	t_config	*config;

	print_header();
	i = 0;
	while (++i <= master->config->number_of_philosophers)
	{
		pthread_create(&master->first->action, NULL, &launch, master->first);
		master->first = master->first->right;
	}
	master->start = gettime();
	pthread_create(&monitoring, NULL, &monitor, master);
	i = 0;
	while (++i <= master->config->number_of_philosophers)
	{
		pthread_join(master->first->action, NULL);
		master->first = master->first->right;
		master->finish++;
	}
	pthread_join(monitoring, NULL);
	print_bottom();
}

void	*launch(void *user)
{
	t_philo		*philo;

	philo = (t_philo *)user;
	philo->time = gettime();
	philo->life = gettime();
	philo->status = THINK;
	while ((philo->eated < philo->config->nbr_philo_must_eat
			|| philo->config->nbr_philo_must_eat < 0)
		&& *philo->state != DEAD)
	{
		if (philo->left->status != EAT)
		{
			philo->status = EAT;
			eating(philo);
			sleeping(philo);
			//thinking(philo);
			//printf("ID: %lu - Time: %ld\n", philo->id, philo->life);
		}
	}
	if (*philo->state == DEAD)
		return (NULL);
	printf("║Philosopher ║       %4ld ║         👌       ║▒\n", philo->id);
	return (NULL);
}

void	print_header(void)
{
	printf("╔════════════╦════════════╦══════════════════╗\n");
	printf("║    Time    ║    Philo   ║       Event      ║\n");
	printf("╠════════════╬════════════╬══════════════════╣▒\n");
}

void	print_bottom(void)
{
	printf("╚════════════╩════════════╩══════════════════╝▒\n");
	printf("  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
}
