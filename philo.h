/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:28:24 by stissera          #+#    #+#             */
/*   Updated: 2022/05/28 10:46:12 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# define DEAD 1

// Messages
# define MALLOC_ERR "Erreur de malloc."
# define NO_PHILO "Aucun philosopher."
# define THREAD_ERR "Erreur de Thread."
# define ARG_INV "Argument(s) invalide!"
# define FORK_MSG "Take a fork 🥢"
# define EAT_MSG "Is eating 🥣"
# define SLEEP_MSG "Is sleeping 😴"
# define THINK_MSG "Is thinking 🤔"
# define DEAD_MSG "\033[0;31mIs DEAD! 💀      \033[0m"

struct	s_philo;

typedef struct s_config
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_philo_must_eat;
	long			start;
	int				end;
	pthread_mutex_t	writing;
	pthread_mutex_t	monitoring;
	struct s_philo	*philosophers;
}	t_config;

typedef struct s_philo
{
	size_t			id;
	pthread_t		action;
	int				need_eat;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	long			time;
	t_config		*config;
}	t_philo;

// Parsse and take the arguments
int		arg_take(t_config *config, int argc, char **argv);//
int		bad_arg(char *arg);

// Philosophers structure
int		create_philo(t_config *config);
void	free_philo(t_config *config);

// Utils
int		ft_atoi(char *nbr);
int		ft_isdigit(char *nbr);
long	gettime(void);

// Start simulation
int		routine(t_config *master);
void	*launch(void *user);
void	takefork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

int		msg_error(char *msg);
void	*monitor(void *master);
void	print_header(t_config *config);
void	print_status(int id, t_philo *philo, char *status);
void	print_bottom(t_config *config);
void	finish(t_philo *philo);
#endif