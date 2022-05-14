/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:54:15 by stissera          #+#    #+#             */
/*   Updated: 2022/05/14 16:09:02 by stissera         ###   ########.fr       */
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
	t_master	*master;
	t_philo		*philo;
	long		time;

	master = (t_master *) s;
	philo = master->first;
	while (master->finish == 0)
	{
		time = gettime() - master->first->life;
		if (time > master->config->time_to_die && master->first->state != DEAD)
		{
			master->first->state = DEAD;
			printf("║%11ld ║%11ld ║\033[0;31m%-18s\033[0m║▒\n",
				time, philo->id, " is DEAD!");
		}
		philo = philo->left;
	}
	return (NULL);
}
