/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/05/03 01:00:15 by stissera         ###   ########.fr       */
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
	routine(&config, &master);
	free_philo(&config, &master);
	return (0);
}

void	routine(t_config *config, t_master *master)
{
	t_philo	*min_eated;

	min_eated = 0;
	gettime(master, config);
	pthread_attr_init(); // continius check thread
	while (min_eated != config->number_of_times_each_philosopher_must_eat)
	{
		min_eated = get_id_mintime(master);

		
	}
}
