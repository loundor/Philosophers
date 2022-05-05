/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:54:15 by stissera          #+#    #+#             */
/*   Updated: 2022/05/02 21:34:55 by stissera         ###   ########.fr       */
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
