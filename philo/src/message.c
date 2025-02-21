/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:50:52 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/21 13:50:56 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	message(t_philo *philo, int state)
{
	time_t curr;

	pthread_mutex_lock(&philo->data->printing);
	curr = ft_get_time()- philo->data->start_time;
	if (!philo)
		return ;
	if (state == 1)
		printf("[ %ld ] Philo %d %s\n", curr, philo->id, TAKE_FORKS);
	else if (state == 2)
		printf("[ %ld ] Philo %d %s\n", curr, philo->id, THINKING);
	else if (state == 3)
		printf("[ %ld ] Philo %d %s\n", curr, philo->id, SLEEPING);
	else if (state == 4)
		printf("[ %ld ] Philo %d %s\n", curr, philo->id, EATING);
	else if (state == 5)
		printf("[ %ld ] Philo %d %s\n", curr, philo->id, DIED);
	pthread_mutex_unlock(&philo->data->printing);
}
