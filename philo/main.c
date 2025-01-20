#include "philo.h"

void ft_put_error(char *s)
{
    while (*s)
        write(2, s++, 1);
}

int ft_error(int i)
{
    if (i == 1)
        ft_put_error("invalid args\n");
    if (i == 2)
        ft_put_error("invalid args\n");
    return (1);
}

int ft_check(char c)
{
    return (c >= '0' && c <= '9');
}

size_t ft_atos(char *s)
{
    int i;
    size_t res;

    i = 0;
    res = 0;
    while (s[i])
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return (res);
}

size_t ft_get_number(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!ft_check(s[i]))
            return (0);
        i++;
    }
    return (ft_atos(s));
}

int ft_parse_data(char **v, t_philo *data)
{
    data->n_philo = ft_get_number(v[1]);
    if (data->n_philo == 0)
        return (1);
    data->time_die = ft_get_number(v[2]);
    if (data->time_die == 0)
        return (1);
    data->time_eat = ft_get_number(v[3]);
    if (data->time_eat == 0)
        return (1);
    data->time_sleep = ft_get_number(v[4]);
    if (data->time_sleep == 0)
        return (1);
    return (0);
}

void ft_print(t_philo *data)
{
    printf("%ld\n", data->n_philo);
    printf("%ld\n", data->time_die);
    printf("%ld\n", data->time_eat);
    printf("%ld\n", data->time_sleep);
}

int main(int c, char **v)
{
    t_philo data;
    int err;

    err = 0;
    if (c != 5)
        return (ft_error(1));
    err = ft_parse_data(v, &data);
    if (err > 1)
        return (ft_malloc(-1), ft_error(2));
    ft_print(&data);
    return (0);
}
