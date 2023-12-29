#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct s_data;

typedef struct s_philo
{
    int nbr;
    int philo_ate;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    struct s_data *data;
    pthread_t thread_nbr;

}t_philo;

typedef struct s_data
{
    int philo_nbr;
    int time_death;
    int time_eat;
    int time_sleep;
    int meal;
    int died;
    int all_eat;
    pthread_mutex_t meal_check;
    pthread_mutex_t *forks;
    pthread_mutex_t write;
    t_philo *philos;
}t_data;

#endif