/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:38:14 by stissera          #+#    #+#             */
/*   Updated: 2022/04/30 12:05:01 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_config	config;
	t_master	master;

	arg_take(&config, argc, argv);
	master.first = create_philo(&config);
	return (1);
}

t_master	*create_philo(t_config *config)
{
	t_master 

	return(philo);
}

void	arg_take(t_config *config, int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Miss arguments\n");
		printf("Use like: ./philo nbrPhilo TimeD TimeE TimeS [NdEat].\n");
		exit(0);
	}
	if (!ft_isdigit(argv[1]) || !ft_isdigit(argv[2]) || !ft_isdigit(argv[3])
		|| !ft_isdigit(argv[3]))
	{
		printf("Bad arguments!\n");
		printf("Use like: ./philo nbrPhilo TimeD TimeE TimeS [NdEat].\n");
		exit(0);
	}
	config->number_of_philosophers = ft_itoa(argv[1]);
	config->time_to_die = ft_itoa(argv[2]);
	config->time_to_eat = ft_itoa(argv[3]);
	config->time_to_sleep = ft_itoa(argv[4]);
	if (argv[5] && ft_isdigit(argv[5]))
		config->number_of_times_each_philosopher_must_eat = ft_itoa(argv[5]);
	else
		config->number_of_times_each_philosopher_must_eat = 0;
}
