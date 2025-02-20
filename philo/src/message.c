/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:50:52 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/20 18:01:29 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	message(t_philo *philo, int state)
{
	if (!philo)
		return ;
	if (state == 1)
		printf("Philo %d %s\n", philo->id, TAKE_FORKS);
	else if (state == 2)
		printf("Philo %d %s\n", philo->id, THINKING);
	else if (state == 3)
		printf("Philo %d %s\n", philo->id, SLEEPING);
	else if (state == 4)
		printf("Philo %d %s\n", philo->id, EATING);
	else if (state == 5)
		printf("Philo %d %s\n", philo->id, DIED);
	else
		return ;
}
