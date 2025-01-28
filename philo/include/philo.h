/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:14:29 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/28 23:13:44 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "string.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}t_gb;

typedef struct s_philo
{
	size_t	n_philo;
	time_t	time_die;
	time_t	time_eat;
	time_t	time_sleep;
	size_t	n_of_eats;
}t_philo;

typedef struct s_info
{
	int				id;
	pthread_t		philo;
	t_philo			*data;
	struct s_info	*next;	
}t_info;

void	*ft_malloc(ssize_t len);
void	ft_put_error(char *s);
int		ft_error(int i);
int		ft_check(char c);
int		ft_parse_data(char **v, t_philo *data);
size_t	ft_get_number(char *s);
int		ft_check_sing(char *s, int i);
int		ft_isnum(char c);
size_t	ft_atos(char *s);
int		ft_init(t_info *data);
int		ft_create_philo(t_philo *data, t_info **head);
time_t	ft_get_time(void);

#endif