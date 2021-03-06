/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:54:15 by stissera          #+#    #+#             */
/*   Updated: 2022/07/07 17:45:29 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_atoi(char *nbr)
{
	int	ret;	
	int	neg;

	neg = 1;
	ret = 0;
	while (*nbr == ' ')
		nbr++;
	if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			neg = -1;
		nbr++;
	}
	while (*nbr && *nbr >= '0' && *nbr <= '9')
	{
		ret *= 10;
		ret += *nbr - 48;
		nbr++;
	}
	ret *= neg;
	return (ret);
}

int	ft_isdigit(char *nbr)
{
	while (*nbr == ' ')
		nbr++;
	if (*nbr == '+' || *nbr == '-')
		nbr++;
	while (*nbr)
	{
		if (*nbr >= '0' && *nbr <= '9')
			nbr++;
		else
			return (0);
	}
	return (1);
}

void	*monitor(void *s)
{
	t_philo		*philo;
	long		time;
	int			i;

	philo = (t_philo *) s;
	while (philo->need_eat)
	{
		time = gettime();
		if (!philo->need_eat)
			return (NULL);
		if (time - philo->time >= philo->config->time_to_die
			&& is_dead(philo->config->end))
		{
			print_status(philo->id, philo, DEAD_MSG);
			philo->config->end = DEAD;
			i = 0;
			sem_wait(philo->config->writing);
			while (i++ < philo->config->number_of_philosophers)
				sem_post(philo->config->deadphilo);
			exit (0);
		}
	}
	return (NULL);
}
