/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/05/05 15:10:55 by stissera         ###   ########.fr       */
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
	routine(&config, &master);
	free_philo(&config, &master);
	return (0);
}

void	routine(t_config *config, t_master *master)
{
	t_philo		*need_eat;
	pthread_t	monitoring;
	size_t		i;

	need_eat = master->first;
	gettime(master, config);
	pthread_create(&monitoring, NULL, monitor, master);  /// TO SEE
	i = 0;
	while (!master->dead || master->first->eated == config->nbrt_philo_must_eat)
	{
		while (++i <= config->number_of_philosophers)
		{
			if (master->first->state == 0
				&& master->first->life < need_eat->life
				&& master->first->action == 0)
				need_eat = master->first;
			master->first = master->first->left;
			master->last = master->first->right;
		}
		do_action(need_eat);
		master->first = master->first->left;
	}
	pthread_detach(monitoring);
}
