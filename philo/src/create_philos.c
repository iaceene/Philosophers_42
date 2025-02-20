/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:01:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/20 18:42:06 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int start_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->printing, NULL) != 0)
		return (1);
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
		data->philo[i].right_fork = &data->forks[i];
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
		if (pthread_join(data->philo[i].thread_id, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_philos(t_data *data)
{
	size_t	i;

	i = 0;
	data->start_time = ft_get_time();
	while (i < data->n_philo)
	{
		data->philo[i].last_eat = ft_get_time();
		data->philo[i].alive = true;
		if (pthread_create(&data->philo[i].thread_id, NULL, routine, &data->philo[i]) != 0)
			return (1);
		usleep(100);
		i++;
	}
	if (ft_join_philos(data))
		return (1);
	return (0);
}
