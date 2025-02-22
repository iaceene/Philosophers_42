/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:01:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/22 13:17:02 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	start_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (ft_destroy_mutexes(data, i), 1);
		i++;
	}
	if (pthread_mutex_init(&data->printing, NULL) != 0)
		return (ft_destroy_mutexes(data, -1), 1);
	return (0);
}

void	inialize_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = (int)i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].meals_eaten = 0;
		data->philo[i].left_fork = &data->forks[i];
		if (i == data->n_philo - 1)
			data->philo[i].right_fork = &data->forks[0];
		else
			data->philo[i].right_fork = &data->forks[i + 1];
		i++;
	}
}

int	ft_join_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_detach(data->philo[i].thread_id))
			return (1);
		i++;
	}
	if (pthread_join(data->monitor_id, NULL) != 0)
		return (1);
	return (0);
}

int	ft_create_philos(t_data *data)
{
	size_t	i;

	i = 0;
	data->all_started = false;
	while (i < data->n_philo)
	{
		data->philo[i].last_eat = ft_get_time();
		data->philo[i].data = data;
		data->philo[i].alive = true;
		if (pthread_create(&data->philo[i].thread_id, NULL,
				routine, &data->philo[i]) != 0)
			return (1);
		i++;
	}
	data->all_started = true;
	data->end_simu = false;
	data->start_time = ft_get_time();
	if ((pthread_create(&data->monitor_id, NULL,
			monitor, data) != 0) || ft_join_philos(data))
		return (1);
	return (0);
}
