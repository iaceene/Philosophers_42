/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/21 18:33:40 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor(void *args)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)args;
	while (!data->end_simu)
	{
		i = 0;
		while (i < data->n_philo)
		{
			if ((ft_get_time() - data->philo[i].last_eat) == data->time_die)
			{
				data->end_simu = true;
				message(&data->philo[i], 5);
				break;
			}
			i++;
		}
	}
	
	return (NULL);
}

void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
int		is_odd(int d);

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->data->all_started);
	while (!philo->data->end_simu)
	{
		if (is_odd(philo->id))
		{
			ft_eat(philo);
			ft_sleep(philo);
		}
		else
		{
			ft_sleep(philo);
			ft_eat(philo);
		}
		message(philo, 2);
	}
	return (NULL);
}

void	ft_sleep(t_philo *philo)
{
	message(philo, 3);
	usleep(philo->data->time_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	message(philo, 1);
	pthread_mutex_lock(philo->left_fork);
	message(philo, 1);
	message(philo, 4);
	philo->last_eat = ft_get_time();
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int		is_odd(int d)
{
	if (d % 2 == 0)
		return (1);
	return (0);
}