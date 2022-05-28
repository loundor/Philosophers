/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/05/21 11:01:17 by stissera         ###   ########.fr       */
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
	master.sema = sem_open("forks", O_CREAT, 0600,
			config.number_of_philosophers);
	setting = 1;
	while (setting <= config.number_of_philosophers)
		master.first->pid = fork();
	
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

	master->start = gettime();
	pthread_create(&monitoring, NULL, &monitor, master);
	print_header();
	i = 0;
	while (++i <= master->config->number_of_philosophers)
	{
		pthread_create(&master->first->action, NULL, &launch, master->first);
		master->first = master->first->right;
	}
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
	philo->status = THINK;
	while ((philo->eated < philo->config->nbr_philo_must_eat
			|| philo->config->nbr_philo_must_eat == -1)
		&& *philo->state != DEAD)
	{
		if (philo->left->status != EAT)
		{
			philo->status = EAT;
			eating(philo);
			sleeping(philo);
			thinking(philo);
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
