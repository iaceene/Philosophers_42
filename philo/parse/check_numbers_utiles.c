/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:04:36 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/20 20:16:26 by yaajagro         ###   ########.fr       */
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
		ft_put_error("invalid args\n");
	if (i == 2)
		ft_put_error("invalid numbers\n");
	return (1);
}

int	ft_check(char c)
{
	return ((c >= '0' && c <= '9') || c == '+'
		|| c == ' ' || c == '\t');
}
