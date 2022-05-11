/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:56:12 by stissera          #+#    #+#             */
/*   Updated: 2022/05/11 18:34:28 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// DEBUG ZONE **************************
/* 	i = 0;
	master = first;
	while (++i <= config->number_of_philosophers)
	{
		printf("Life time of %ld start at %ld.%6d\n", master->first->left->life,
			master->first->left->start.tv_sec,
			master->first->left->start.tv_usec);
		master->first = master->first->left;
	} */

// IF ONLY THIS FUNCTION, put it in utils...
long	gettime(void)
{
	struct timeval	starttime;
	long			ret;

	gettimeofday(&starttime, NULL);
	ret = ((starttime.tv_sec % 10000) * 1000000)
		+ starttime.tv_usec;
//printf("Gettime: %ld", ret);
	return (ret);
}
