#ifndef PHILO_H
#define PHILO_H

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}t_gb;

#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
#include "time.h"

void	*ft_malloc(ssize_t len);

#endif