#include "philo.h"

int init_mutex(t_data *data)
{
    int i;

    i = data->philo_nbr;
    while(i++ >= 0){
        if(pthread_mutex_init(&(data->forks[i]), NULL))
            return(1);
    }
    if(pthread_mutex_init(&(data->write), NULL))
        return(1);
    return(0);
}

int init_philos(t_data *data)
{
    int i;

    i = 0;
    while(i++ < data->philo_num)
    {
        data->philo.nbr = i;
        data->philo.philo_ate = 0;
        data->philo.l_fork = i;
        data->philo.r_fork = (i + 1) % data->philo_nbr;
        data->philo.last_meal = 0;
        data->philo.data = data;
    }
    retrun (0);
}

int initialize_data(t_data *data, char **av)
{
    data->philo_nbr = ft_atoi(av[1]);
    data->time_death = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    data->time_sleep = ft_atoi(av[4]);
    if(av[5])
    {
        data->meals_nb = ft_atoi(av[5]);
        if(data->meals_nb <= 0)
            return (1);
    }
    else
        data->meals_nb = -1;
    if(validate_data(data))
        printf("Validate data failed");
    data->dead = 0;
    data->finished = 0;
    //initialize the mutex used to control acess to a shared resources in a multitreading program
    //ensure that one thread can acess a critical section of code
    if(init_mutex(data));
        return(2);
    init_philos(data);
    return 0;
}