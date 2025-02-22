/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:12:27 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/22 13:15:30 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int c, char **v)
{
	t_data	data;
	int		err;

	err = 0;
	if (c < 5 || c > 6)
		return (ft_error(1));
	err = ft_parse_data(v, &data);
	if (err == 1)
		return (ft_malloc(-1), ft_error(2));
	err = start_mutexes(&data);
	if (err == 1)
		return (ft_malloc(-1), ft_error(3));
	inialize_philos(&data);
	err = ft_create_philos(&data);
	if (err == 1)
		return (ft_destroy_mutexes(&data, data.n_philo),
			ft_malloc(-1), ft_error(3));
	return (ft_destroy_mutexes(&data, data.n_philo),
		ft_malloc(-1), 0);
}
