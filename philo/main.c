#include "philo.h"

void ft_put_error(char *s)
{
    while (*s)
        write(2, s++, 1);
}

void ft_error(int i)
{
    if (i == 1)
        ft_put_error("invalid args\n");
}

int main(int c, char **v)
{
    (void)v;
    if (c != 5)
        ft_error(1);
    return (0);
}