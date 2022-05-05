/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:28:24 by stissera          #+#    #+#             */
/*   Updated: 2022/05/05 15:10:37 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3

typedef struct s_config
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbrt_philo_must_eat;
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
	int				action;
}	t_philo;

typedef struct s_master
{
	t_philo		*first;
	t_philo		*last;
	t_config	*config;
	int			dead;
}	t_master;

// Parsse and take the arguments
void		arg_take(t_config *config, int argc, char **argv);

// Philosophers structure
int			create_philo(t_config *config, t_master *master);
void		push_next_philo(t_philo *philo, t_philo *philof, t_master *master);
t_philo		*push_first_philo(t_philo *philo, t_master *master);
void		free_philo(t_config *config, t_master *master);

// Utils
int			ft_atoi(char *nbr);
int			ft_isdigit(char *nbr);

// Start simulation
void		routine(t_config *config, t_master *master);
void		gettime(t_master *first, t_config *config);
long		get_id_time(t_philo *philo);
void		eating(t_philo *philo, t_config *config);
void		sleeping(t_philo *philo, t_config *config);
void		thinking(t_philo *philo, t_config *config);
void		do_action(t_philo *need_eat);

// Check and give orders to philosophers
#endif