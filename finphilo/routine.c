#include "philo.h"

void eat(t_philo *philo){
    t_data *data;

    data = philo->data;
    pthread_mutex_lock(&(data->forks[philo->l_fork]));
    printf("Has taken the left fork");
    pthread_mutex_lock(&(data->forks[philo->r_fork]));
    printf("Has taken the right fork");
    pthread_mutex_lock(&(data->meal_check));
    printf("Philo is eating!");
    philo->last_meal = get_time();
    pthread_mutex_unlock(&(data->meal_check));
    sleep(data->time_eat, data);
    (philo->philo_ate)++;
    pthread_mutex_unlock(&(data->forks[philo->l_fork]));
    pthread_mutex_unlock(&(data->forks[philo->r_fork]));
}
void *action(void *void_argv)
{
    int i;

    t_philo *philos;
    t_data *data;

    i = 0;
    philos = (t_philo *)void_argv;
    data = philo->data;
    while(!(data->died))
    {
        eat(philo); //create the function eat
        if(data->all_eat)
            break;
        printf("Philo is sleeping!");
        sleep(data->time_sleep, data); //create the function sleep
        printf("Philo is thinking!");
        i++;
    }
    return (NULL);
}

void quit(t_data *data, t_philo *philos){
    int i;

    i = -1;
    while(++i < data->philo_nbr)
        pthread_join(philo[i].thread_nbr, NULL);
    i = -1;
    while(++i < data->philo_nbr)
        pthread_mutex_destroy(&(data->forks[i]));
    pthread_mutex_destroy(&(data->write));

}
void check_death(t_data *p, t_philo *philo)
{
    while(!(p->all_ate))
    {
        i = -;
        while(++i < p->philo_nbr && !(p->dead))
        {
            pthread_mutex_lock(&(p->meal_check));
            if(get_time() >= p->time_death && p->eating == 0)
            {
                printf("DIED");
                p->died = 1;
            }
        }
        pthread_mutex_unlock(&(p->meal_check));
        usleep(100);
    }
}

int thread(t_data *data)
{
    int i;
    t_philo *plilosopher;

    i = 0;
    philosopher = data->philo;
    data->first_time = get_time();
    while(i < data->philo_nbr){
        if(pthread_create(&(philosopher[i].thread_nbr), NULL, boring_routine, &(philosopher[i])))
            return (1);
        philosopher[i].last_meal = get_time;
        i++;
    }
    check_death(data, data->philosopher);
    quit(data, philosopher);
    return (0);
}