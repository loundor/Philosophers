/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:54:15 by stissera          #+#    #+#             */
/*   Updated: 2022/05/05 18:45:08 by stissera         ###   ########.fr       */
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

void	monitor(t_master *master)
{
	t_philo	*philo;
	long	time;

	time = (((master->first->start.tv_sec % 10000) * 1000000)
			+ master->first->start.tv_usec);
	philo = master->first;
	while (time - philo->life < master->config->time_to_die)
	{
		philo = philo->left;
		time = (((master->first->start.tv_sec % 10000) * 1000000)
				+ master->first->start.tv_usec);
	}
	printf ("%ld %ld died!!!", ((master->first->start.tv_sec % 10000) * 1000000)
		+ master->first->start.tv_usec, philo->id);
	master->dead = DEAD;
}
