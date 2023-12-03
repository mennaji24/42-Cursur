#include "philo.h"

static const char* MessageTypeStrings[] = 
{
    "TAKING RIGHT FORK",
    "EATING",
    "THINKING",
    "SLEEPING"
};

void message(MessageType, t_philo *philo)
{
    const char *message;

    message = MessageTypeStrings[MessageType];
    printf("[%d ms] Philosopher %d %s\n", get_time(), philo->id, message_type_str);
}

int get_time(void)
{
    struct timeval *tv;

    if(gettingofday(&tv, NULL) != )
    {
        ft_error("Failure:(");
        return (-1);
    }
    return ((tv.tv_sec *1000) + (tv.tv_usec / 1000));
}

void time_to_eat(t_philo *philo)
{
    int time_of_death;
    int eat_count;

    eat_count = 0;
    time_of_death = get_time + philo->death_time;
    philo_take_fork(philo);
    pthreads_mutex_lock(philo->lock);
    philo->eating = 1;
    philo->time_to_die = time_of_death;
    message(EATING, philo);
    eat_count++;
    time_to_sleep(philo->eating);
    philo->eating = 1;
    pthreads_mutex_unlock(philo->lock);
    philo_drops_fork(philo);
}

int time_to_sleep(suseconds_t time)
{  
    u_int64_t start_time;
    
    start_time = get_time();
    result = start_time - time;
    while(result_time < time)
    {
        printf("Philosopher is sleeping\n");1
        usleep((time - result) * 1000);
        result_time = get_time() - start_time; //update the result_time for the next iteration 
    }
    return(0);
}

void *philo_take_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    message(TAKE_R_FORK, philo);
    pthread_mutex_lock(philo->l_fork);
    message(TAKE_L_FORK, philo);
}

void *philo_drops_fork(t_philo *philo){
    pthread_mutex_unlock(philo->r_fork);
    phtread_mutex_unlock(philo->l_fork);
    message(DROP_FORKS, PHILO);
    time_to_sleep();
}

void routine_philosopher(t_philo *philo)
{
    while(true){
        philo_take_fork(philo);
        time_to_eat(philo);
        time_to_sleep(philo);
        philo_drops_fork(philo);
    }
}
