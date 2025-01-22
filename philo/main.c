/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:12:27 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/22 21:22:23 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int c, char **v)
{
	t_philo	data;
	t_info	*info;
	int		err;

	err = 0;
	info = NULL;
	if (c < 5 || c > 6)
		return (ft_error(1));
	err = ft_parse_data(v, &data);
	if (err == 1)
		return (ft_malloc(-1), ft_error(2));
	err = ft_create_philo(&data, &info);
	if (err == 1)
		return (ft_malloc(-1), ft_error(3));
	return (0);
}
