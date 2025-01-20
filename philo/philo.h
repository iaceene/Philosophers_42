#ifndef PHILO_H
#define PHILO_H

#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
#include "time.h"

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}t_gb;

typedef struct s_philo
{
    size_t  n_philo;
    size_t  time_die;
    size_t  time_eat;
    size_t  time_sleep;
}t_philo;



void	*ft_malloc(ssize_t len);

#endif