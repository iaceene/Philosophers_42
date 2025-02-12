/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:01:06 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/12 00:52:49 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_atos(char *s)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (ft_isnum(s[i]) || s[i] == '+')
	{
		if (!(s[i] == '+'))
			res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_check_sing(char *s, int i)
{
	if (s[i] == '+' && s[i + 1])
		if (ft_isnum(s[i + 1]) && !ft_isnum(s[i - 1]))
			return (1);
	return (0);
}

size_t	ft_get_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_check(s[i]))
			return (0);
		if (s[i] == '+' && !ft_check_sing(s, i))
			return (0);
		i++;
	}
	return (ft_atos(s));
}

int	ft_parse_data(char **v, t_philo *data)
{
	data->n_philo = ft_get_number(v[1]);
	if (data->n_philo == 0)
		return (1);
	data->time_die = (time_t)ft_get_number(v[2]);
	if (data->time_die == 0)
		return (1);
	data->time_eat = (time_t)ft_get_number(v[3]);
	if (data->time_eat == 0)
		return (1);
	data->time_sleep = (time_t)ft_get_number(v[4]);
	if (data->time_sleep == 0)
		return (1);
	if (v[5])
	{
		data->nofeats_flag = true;
		data->n_of_eats = ft_get_number(v[5]);
		if (data->time_sleep == 0)
			return (1);
	}
	else
		data->nofeats_flag = false;
	return (0);
}
