/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:56:12 by stissera          #+#    #+#             */
/*   Updated: 2022/05/14 18:57:57 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long	gettime(void)
{
	struct timeval	starttime;
	long			ret;

	gettimeofday(&starttime, NULL);
	ret = ((starttime.tv_sec * 10000)
			+ (starttime.tv_usec / 1000));
	return (ret);
}
