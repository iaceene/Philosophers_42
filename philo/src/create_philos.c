/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:01:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/22 21:22:55 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_info *new_philo(int id)
{
	t_info	*new_philo;

	new_philo = ft_malloc(sizeof(t_info));
	if (!new_philo)
		return (NULL);
	new_philo->id = id;
	new_philo->next = NULL;
	return (new_philo);
}

t_info *last_philo(t_info **head)
{
	t_info *tmp;

	tmp = *head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int ft_add_philo(t_info **head, t_info *new)
{
	t_info *tmp;
	t_info *last;

	if (!head || !new)
		return (1);
	tmp = *head;
	if (!tmp)
	{
		head = new;
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
	int i;
	int err;

	err = 0;
	i = 0;
	while (i < data->n_philo)
	{
		err = ft_add_philo(head, new_philo(i));
		if (err == 1)
			return (1);
		i++;
	}
	return (0);
}
