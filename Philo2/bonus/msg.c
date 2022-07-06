/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:22:37 by stissera          #+#    #+#             */
/*   Updated: 2022/06/17 10:06:11 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	msg_error(char *msg)
{
	printf("%s", msg);
	return (0);
}

void	print_status(int id, t_philo *philo, char *status)
{
	is_dead(philo->config->end);
	sem_wait(philo->config->writing);
	if (!philo->config->end)
		printf("║%11ld ║%11ld ║ %-19s║▒ %ld\n", gettime() - philo->config->start,
			philo->id + 1, status, philo->config->writing->__align);
	sem_post(philo->config->writing);
}

void	print_header(t_config *config)
{
	sem_wait(config->writing);
	printf("╔════════════╦════════════╦══════════════════╗\n");
	printf("║    Time    ║    Philo   ║       Event      ║\n");
	printf("╠════════════╬════════════╬══════════════════╣▒\n");
	sem_post(config->writing);
}

void	print_bottom(t_config *config)
{
	sem_wait(config->writing);
	printf("╚════════════╩════════════╩══════════════════╝▒\n");
	printf("  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
	sem_post(config->writing);
}

void	finish(t_philo *philo)
{
	if (philo->config->end == 0)
	{
		sem_wait(philo->config->writing);
		printf("║\033[0;32mPhilosopher \033[0m║");
		printf("\033[0;32m       %4ld \033[0m║", philo->id + 1);
		printf("\033[0;32m         👌       \033[0m║▒\n");
		sem_post(philo->config->writing);
		exit (0);
	}
}
