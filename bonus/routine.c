/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:56:12 by stissera          #+#    #+#             */
/*   Updated: 2022/07/07 16:44:52 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long	gettime(void)
{
	struct timeval	starttime;
	long			ret;

	gettimeofday(&starttime, NULL);
	ret = ((starttime.tv_sec * 1000)
			+ (starttime.tv_usec / 1000));
	return (ret);
}

int	is_dead(int dead)
{
	if (dead)
		exit (0);
	return (1);
}
