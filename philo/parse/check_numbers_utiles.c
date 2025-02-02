/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:04:36 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/21 10:28:42 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_put_error(char *s)
{
	while (*s)
		write(2, s++, 1);
}

int	ft_error(int i)
{
	if (i == 1)
	{
		ft_put_error("Error : Invalid Arguments\nUsage : ");
		ft_put_error("./philo [number_of_philo] [time_to_die] ");
		ft_put_error("[time_to_eat] [time_to_sleep]\n");
	}
	if (i == 2)
	{
		ft_put_error("Error : Invalid Numbers\nUsage : ");
		ft_put_error("./philo 60 60 60 60\n");
	}
	if (i == 3)
		ft_put_error("Error : an error occurred while launching...\n");
	return (1);
}

int	ft_check(char c)
{
	return ((c >= '0' && c <= '9') || c == '+'
		|| c == ' ' || c == '\t');
}
