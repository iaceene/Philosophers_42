/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:08:19 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/22 13:27:53 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_destroy_mutexes(t_data *data, int start)
{
	int	i;
	int final;

	if (start == -1)
		final = data->n_philo;
	else
		final = start;
	i = 0;
	while (i < final)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if ((start != -1) && (i == (int)data->n_philo - 1))
		pthread_mutex_destroy(&data->printing);
}
