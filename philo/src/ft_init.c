/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/27 21:37:02 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philos_rotin(void *args)
{
	t_info	*data;
	pthread_mutex_t locker;

	pthread_mutex_init(&locker, NULL);
	pthread_mutex_lock(&locker);
	data = (t_info *)args;
	printf("done ! from %d\n", data->id);
	pthread_mutex_unlock(&locker);
	return (NULL);
}

int	ft_create_threads(t_philo *data)
{
	t_info	*tmp;
	int		i;
	int		err;

	i = 1;
	tmp = data->philos;
	while (tmp)
	{
		tmp->id = i;
		err = pthread_create(&tmp->philo, NULL, philos_rotin, (void *)data->philos);
		if (err != 0)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	ft_join_threads(t_info *head)
{
	int	err;

	while (head)
	{
		err = pthread_join(head->philo, NULL);
		if (err != 0)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_init(t_philo *data)
{
	int	err;

	err = ft_create_threads(data);
	if (err == 1)
		return (1);
	err = ft_join_threads(data->philos);
	if (err == 1)
		return (1);
	return (0);
}
