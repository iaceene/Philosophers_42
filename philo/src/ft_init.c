/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/21 19:33:47 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_check_meals(t_philo *philo)
{
	int flag;
	size_t count;
	size_t i;

	flag = 0;
	i = 0;
	count = 0;
	if (philo->meals_eaten == philo->data->n_of_eats)
		flag = 1;
	while (i < philo->data->n_philo)
	{
		if (philo->meals_eaten == philo->data->n_of_eats)
			count++;	
		i++;
	}
	if (count == philo->data->n_philo)
		return (1);
	else if (flag == 1)
		return (99);
	else
		return (-1);
	return (0);
}

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
				if (data->n_of_eats_f)
				{
					int err = ft_check_meals(&data->philo[i]);
					if (err == 1)
					{
						data->end_simu = true;
						break;
					}
					else if (err == -1)
					{
						data->end_simu = true;
						message(&data->philo[i], 5);
						break;
					}
				}
				else
				{
					data->end_simu = true;
					message(&data->philo[i], 5);
					break;
				}
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
		message(philo, 2);
		if (philo->data->n_of_eats_f
			&& philo->meals_eaten >= philo->data->n_of_eats)
			break ;
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
	philo->meals_eaten++;
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