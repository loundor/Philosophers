/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:28:24 by stissera          #+#    #+#             */
/*   Updated: 2022/04/30 12:04:59 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_config
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_times_each_philosopher_must_eat;
}	t_config;

typedef struct s_master
{
	t_philo	*first;
	t_philo	*last;
}	t_master;

typedef struct s_philo
{
	size_t	id;
	//int		mutex;
	int		state;
	int		fork;
	long	life;
	t_philo	*prev;
	t_philo	*next;
}	t_philo;

void		arg_take(t_config *config, int argc, char **argv);
t_master	*create_philo(t_config *config);
int			ft_atoi(char *nbr);
int			ft_isdigit(char *nbr);
#endif