/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:28:24 by stissera          #+#    #+#             */
/*   Updated: 2022/05/03 00:51:39 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_config
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_times_each_philosopher_must_eat;
}	t_config;

typedef struct s_philo
{
	size_t			id;
	int				state;
	unsigned long	life;
	int				eated;
	struct timeval	start;
	pthread_mutex_t	fork;
	struct s_philo	*left;
	struct s_philo	*right;
}	t_philo;

typedef struct s_master
{
	t_philo	*first;
	t_philo	*last;
}	t_master;

// Parsse and take the arguments
void		arg_take(t_config *config, int argc, char **argv);

// Philosophers structure
int			create_philo(t_config *config, t_master *master);
void		free_philo(t_config *config, t_master *master);

// Utils
int			ft_atoi(char *nbr);
int			ft_isdigit(char *nbr);

// Start simulation
void		routine(t_config *config, t_master *master);
void		gettime(t_master *first, t_config *config);
t_philo		*get_id_mintime(t_master *master);
// Check and give orders to philosophers

#endif