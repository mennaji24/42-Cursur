#include "philo.h"


int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

//race condition in witch one or more threads trying or modify 
void check_death_philo(void *arg)
{
    t_philo* philo = (t_philo*)arg;

    while (!philo->data->dead) {
        // Lock to avoid race condition with philosopher's last meal timestamp
        pthread_mutex_lock(&philo->lock);

        // Check for death condition
        if (!philo->eating && (get_time() - philo->last_meal) > philo->data->death_time) {
            // Philosopher is considered dead
            messages(DIED, philo);
            philo->data->dead = 1;
        }

        // Unlock after checking
        pthread_mutex_unlock(&philo->lock);

        // Sleep for a short interval before checking again
        usleep(1000); // Sleep for 1 millisecond (adjust as needed)
    }
}
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
    if(process(&data)){
        return (error(ERROR_THREADS, data));
        return (1); 
    }
}