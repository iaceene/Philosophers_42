/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/21 15:19:39 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor(void *args)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)args;
	data->still_alive = true;
	while (data->still_alive)
	{
		i = 0;
		while (i < data->n_philo)
		{
			if (data->philo[i].alive == false)
			{
				message(&data->philo[i], 5);
				data->still_alive = false;
				break ;
			}
			i++;
		}
	}
	return (NULL);
}

void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->data->all_started);
	philo->last_eat = ft_get_time();
	while (philo->data->still_alive)
	{
		if (philo->id % 2 == 0)
		{
			ft_sleep(philo);
			ft_eat(philo);
		}
		else
		{
			ft_eat(philo);
			ft_sleep(philo);
		}
		if (ft_get_time() - philo->data->start_time == 3)
			philo->alive = false;
	}
	return (NULL);
}

void	ft_sleep(t_philo *philo)
{
	message(philo, 3);
	usleep(philo->data->time_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	message(philo, 1);
	pthread_mutex_lock(philo->left_fork);
	message(philo, 1);
	usleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}