/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:50:52 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/21 19:11:29 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	message(t_philo *philo, int state)
{
	time_t curr;

	pthread_mutex_lock(&philo->data->printing);
	curr = ft_get_time()- philo->data->start_time;
	if (philo->data->n_of_eats_f)
		printf("[ %ld ] ", philo->meals_eaten);
	if (!philo)
		return ;
	if (state == 1)
		printf("%ld %d %s\n", curr, philo->id, TAKE_FORKS);
	else if (state == 2)
		printf("%ld %d %s\n", curr, philo->id, THINKING);
	else if (state == 3)
		printf("%ld %d %s\n", curr, philo->id, SLEEPING);
	else if (state == 4)
		printf("%ld %d %s\n", curr, philo->id, EATING);
	else if (state == 5)
		printf("%ld %d %s\n", curr, philo->id, DIED);
	pthread_mutex_unlock(&philo->data->printing);
}
