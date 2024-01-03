#include "philo.h"

void eat(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    pthread_mutex_lock(&(data->forks[philo->l_fork]));
    print_message(data, philo->nbr, "Has taken the left fork\n");
    pthread_mutex_lock(&(data->forks[philo->r_fork]));
    print_message(data, philo->nbr, "Has taken the right fork\n");
    pthread_mutex_lock(&(data->meal_check));
    print_message(data, philo->nbr,"Philo is eating!\n");
    philo->last_meal = get_time();
    pthread_mutex_unlock(&(data->meal_check));
    ft_sleep(data->time_eat, data);
    (philo->philo_ate)++;
    pthread_mutex_unlock(&(data->forks[philo->l_fork]));
    pthread_mutex_unlock(&(data->forks[philo->r_fork]));
}

void *action(void *void_argv)
{
    int i;

    t_philo *phi;
    t_data *data;

    i = 0;
    phi = (t_philo *)void_argv;
    data = phi->data;
    //// Introduce a delay for even-numbered philosophers to prevent deadlock
    if (phi->nbr % 2)
        usleep(10000);
    while(!(data->died))
    {
        eat(phi);
        if(data->all_ate)
            break;
        print_message(data, phi->nbr, "Philo is sleeping!\n");
        ft_sleep(data->time_sleep, data);
        print_message(data, phi->nbr, "Philo is thinking!\n");
        i++;
    }
    return (NULL);
}

void quit(t_data *data, t_philo *philos)
{
    int i;

    i = -1;
    while(++i < data->philo_nbr)
        pthread_join(philos[i].thread_nbr, NULL);
    i = -1;
    while(++i < data->philo_nbr)
        pthread_mutex_destroy(&(data->forks[i]));
    pthread_mutex_destroy(&(data->write));

}

void check_death(t_data *p, t_philo *phi)
{
    int i;

    while(!(p->all_ate))
    {
        i = -1;
        while(++i < p->philo_nbr && !(p->died))
        {
            //pthread_mutex_lock(&(p->meal_check));
            //Checks if the current time has exceeded
            //or is equal to the time limit for eating (time_death).
            if(time_delta(phi[i].last_meal, get_time()) > p->time_death)
            {
                print_message(p, i, "DIED\n");
                p->died = 1;
                exit(1);
            }
            //pthread_mutex_unlock(&(p->meal_check));
            usleep(100);
        }
        if(p->died)
            break;
        i = 0;
	    while (p->meal_nbr != -1 && i < p->philo_nbr &&  phi[i].philo_ate >= p->meal_nbr)
		    i++;
	    if (i == p->philo_nbr)
		    p->all_ate = 1;
    }
}

int thread(t_data *data)
{
    int i;
    t_philo *philosopher;

    i = 0;
    philosopher = data->philos;
    data->first_time = get_time();
    while(i < data->philo_nbr)
    {
        if(pthread_create(&(philosopher[i].thread_nbr), NULL, &action, &(philosopher[i])))
            return (1);
        philosopher[i].last_meal = get_time();
        i++;
    }
    //check_death(data, data->philos);
    quit(data, philosopher);
    return (0);
}