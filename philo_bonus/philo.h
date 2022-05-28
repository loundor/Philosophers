/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:28:24 by stissera          #+#    #+#             */
/*   Updated: 2022/05/26 11:54:57 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>
# define THINK 0
# define EAT 1
# define SLEEP 2
# define DEAD 3


typedef struct s_config
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_philo_must_eat;
}	t_config;

typedef struct s_philo
{
	size_t			id;
	t_config		*config;
	pid_t			pid;
	int				status;
	int				state;
	long			life;
	int				eated;
	struct s_philo	*left;
	struct s_philo	*right;
	struct s_master	*master;
	long			time;
}	t_philo;

typedef struct s_master
{
	t_philo			*first;
	t_philo			*last;
	t_config		*config;
	long			start;
	int				finish;
	sem_t			*sema;
}	t_master;

// Parsse and take the arguments
void		arg_take(t_config *config, int argc, char **argv);//
void		bad_arg(void);

// Philosophers structure
int			create_philo(t_config *config, t_master *master);
t_philo		*push_first_philo(t_philo *philo, t_master *master);
void		push_next_philo(t_philo *philo, t_philo *philof, t_master *master);
void		free_philo(t_config *config, t_master *master);

// Utils
int			ft_atoi(char *nbr);
int			ft_isdigit(char *nbr);
long		gettime(void);

// Start simulation
void		routine(t_master *master);
void		*launch(void *user);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

void		*monitor(void *master);
void		print_header(void);
void		print_bottom(void);
#endif