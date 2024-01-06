#include "philo.h"

int init_mutex(t_data *data)
{
    int i;

    i = data->philo_nbr;
    while(--i >= 0)
    {
        if(pthread_mutex_init(&(data->forks[i]), NULL)){
            printf("Error: pthread_mutex_init");
            return(1);
        }
    }
    if(pthread_mutex_init(&(data->write), NULL)){
        printf("Error: pthread_mutex_init");
        return (1);
    }
    if(pthread_mutex_init(&(data->meal_check), NULL)){
        printf("Error: pthread_mutex_init");
        return (1);
    }
    return (0);
}

int init_philos(t_data *data)
{
    int i;

    i = data->philo_nbr;
    data->philos = malloc(sizeof(t_philo) * data->philo_nbr);
    while(--i >= 0)
    {
        data->philos[i].nbr = i;
        data->philos[i].philo_ate = 0;
        data->philos[i].l_fork = i;
        data->philos[i].r_fork = (i + 1) % data->philo_nbr;
        data->philos[i].last_meal = 0;
        data->philos[i].data = data;
    }
    return (0);
}

int validate_data(t_data *data)
{
    if (data->philo_nbr > 200 || data->time_death < 0 ||
        data->time_eat < 0 || data->time_sleep < 0 || data->philo_nbr > 250){
        return 1;  // Invalid data
    }
    return 0;  // Valid data
}

int initialize_data(t_data *data, char **av)
{
    data->philo_nbr = ft_atoi(av[1]);
    data->time_death = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    data->time_sleep = ft_atoi(av[4]);
    data->all_ate = 0;
    data->died = 0;
    if(validate_data(data))
        printf("Validate data failed");
    if(av[5])
    {
        data->meal_nbr = ft_atoi(av[5]);
        if(data->meal_nbr <= 0)
            return (1);
    }
    else
        data->meal_nbr = -1;
    //initialize the mutex used to control acess to a shared resources in a multitreading program
    //ensure that one thread can acess a critical section of code
    if(init_mutex(data)){
        printf("Failed to initiliaze mutex");
        return (1);
    }
    init_philos(data);
    return (0);
}