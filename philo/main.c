#include "philo.h"

//function to simulate the philosopher actions

void  *p_thread(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    philo->time_to_die = philo->data->death_time + get_time();
    while(!(philo->data->dead))
    {
        time_to_eat(philo);
        if(philo->data->all_ate)
            break;
        message(SLEEPING, philo);
        time_to_sleep(philo);
        message(THINKING, philo);
    }
    return (NULL);
}
void destroy_process(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	free_memory(data);
}

int process(t_data *data)
{
    int i;
    t_philo *philo;
    pthread_t thread_ids[data->philo_nbr];  // Array to store thread IDs

    i = 0;
    philo = data->philos;
    data->time = get_time();
    //create the thread for philos
    while(i < data->philo_num)
    {
        philo[i].last_meal = get_time();
        if(pthread_create(&thread_ids[i], NULL, p_thread, &(philo[i])) != 0){
            write(1, "pthread_create", 15);
            return (1);
        }
        i++;
    }
    check_death_philo(data, data->philos);
    destroy_process(data, philo);
}

int main(int ac, char **argv)
{
    t_data *data;
    int  check;
    
    if(ac != 5 && ac != 6){
        return (error(WRONG_NUB_ARG, data));
        return (1);
    }
    check = initialize_data(&data, argv, ac);
    if(check){
        return (error(ONE_OR_MORE_ARGS, data));
        return (1);
    }
}