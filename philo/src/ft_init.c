/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/25 23:24:20 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philos_rotin(void *args)
{
	t_philo	*data;

	data = (t_philo *)args;
	printf("done ! from %d\n", data->tmp_id);
	return ((void *)data->n_of_eats);
}

int	ft_create_threads(t_philo *data)
{
	t_info	*tmp;
	int		err;

	tmp = data->philos;
	while (tmp)
	{
		data->tmp_id = tmp->id;
		err = pthread_create(&tmp->philo, NULL, philos_rotin, (void *)data);
		if (err != 0)
			return (1);
		tmp = tmp->next;
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
