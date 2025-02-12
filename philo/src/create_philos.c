/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:01:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/12 00:30:14 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_info	*new_philo(int id, t_philo *data)
{
	t_info	*new_philo;

	new_philo = ft_malloc(sizeof(t_info));
	if (!new_philo)
		return (NULL);
	new_philo->id = id;
	new_philo->meals_eaten = 0;
	new_philo->last_eat = 0;
	new_philo->alive = true;
	new_philo->data = data;
	new_philo->next = NULL;
	return (new_philo);
}

t_info	*ft_last_philo(t_info **head)
{
	t_info	*tmp;

	tmp = *head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_add_philo(t_info **head, t_info *new)
{
	t_info	*tmp;
	t_info	*last;

	if (!head || !new)
		return (1);
	tmp = *head;
	if (!tmp)
	{
		*head = new;
		return (0);
	}
	else
	{
		last = ft_last_philo(head);
		last->next = new;
	}
	return (0);
}

int	ft_create_philo(t_philo *data, t_info **head)
{
	size_t	i;
	int		err;

	err = 0;
	i = 0;
	while (i < data->n_philo)
	{
		err = ft_add_philo(head, new_philo(i + 1, data));
		if (err == 1)
			return (1);
		i++;
	}
	return (0);
}
