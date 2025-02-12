/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:57:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/12 00:25:17 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philos_rotine(void *args)
{
	t_info	*philo;
	// time_t	cur;
	// time_t	die_t;
	// time_t	tmp;

	philo = (t_info *)args;
	// cur = ft_get_time();
	// die_t = data->data->time_die;
	// while (1)
	// {
	// 		tmp = ft_get_time() - cur;
	// 		if (tmp == die_t)
	// 			break;
	// }
	message(philo, 1);
	return (NULL);
}

int	ft_create_threads(t_info *data)
{
	t_info	*tmp;
	int		i;
	int		err;

	i = 1;
	tmp = data;
	while (tmp)
	{
		tmp->id = i;
		err = pthread_create(&tmp->philo, NULL, philos_rotine, (void *)tmp);
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

int	ft_init(t_info *data)
{
	int	err;

	data->data->start_time = ft_get_time();
	if (data->data->start_time == -1)
		return (1);
	err = ft_create_threads(data);
	if (err == 1)
		return (1);
	err = ft_join_threads(data);
	if (err == 1)
		return (1);
	return (0);
}
