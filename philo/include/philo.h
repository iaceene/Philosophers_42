/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:14:29 by yaajagro          #+#    #+#             */
/*   Updated: 2025/02/12 00:44:26 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdlib.h"
# include "stdbool.h"
# include "stdio.h"
# include "unistd.h"
# include "string.h"
# include "pthread.h"
# include "sys/time.h"

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define RESET   "\x1B[0m"

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
	bool	nofeats_flag;
	time_t	start_time;
	bool	end_simu;
}t_philo;

typedef struct s_info
{
	int				id;
	pthread_t		philo;
	size_t			meals_eaten;
	time_t			last_eat;
	bool			alive;
	t_philo			*data;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
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
void	message(t_info *philo, int state);

#endif