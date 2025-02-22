/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:14:29 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/22 13:17:34 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdlib.h"
# include "stdbool.h"
# include "stdio.h"
# include <unistd.h>
# include "string.h"
# include "pthread.h"
# include "sys/time.h"
# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"
# define RED     "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE    "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define RESET   "\x1B[0m"
# define MAX_NUMBER_PHILO 200

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}t_gb;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	size_t			meals_eaten;
	time_t			last_eat;
	bool			alive;
	struct s_data	*data;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}t_philo;

typedef struct s_data
{
	size_t			n_philo;
	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;
	bool			n_of_eats_f;
	size_t			n_of_eats;
	time_t			start_time;
	bool			end_simu;
	bool			still_alive;
	bool			all_started;
	pthread_t		monitor_id;
	t_philo			philo[MAX_NUMBER_PHILO];
	pthread_mutex_t	forks[MAX_NUMBER_PHILO];
	pthread_mutex_t	printing;
}t_data;

void	*ft_malloc(ssize_t len);
void	ft_put_error(char *s);
int		ft_error(int i);
int		ft_check(char c);
int		ft_parse_data(char **v, t_data *data);
size_t	ft_get_number(char *s);
int		ft_check_sing(char *s, int i);
int		ft_isnum(char c);
size_t	ft_atos(char *s);
time_t	ft_get_time(void);
void	message(t_philo *philo, int state);
// mew
void	inialize_philos(t_data *data);
int		start_mutexes(t_data *data);
int		ft_create_philos(t_data *data);
void	*routine(void *data);
void	*monitor(void *data);
void	ft_destroy_mutexes(t_data *data, int start);
#endif