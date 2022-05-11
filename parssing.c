/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:33:59 by stissera          #+#    #+#             */
/*   Updated: 2022/05/11 16:51:44 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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
	config->number_of_philosophers = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	config->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] && ft_isdigit(argv[5]))
		config->nbrt_philo_must_eat = ft_atoi(argv[5]);
	else
		config->nbrt_philo_must_eat = -1;
}
