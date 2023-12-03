# ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include <sys/time.h>

#define NUM_PHILOSOPHERS 5
#define ERR_IN_2 "Invalid argument"
#define ALLOC_ERR_1 "Failure"
#define WRONG_NUB_ARG "Wrong num of arguments"
#define ONE_OR_MORE_ARGS ""

typedef struct
{
    int philo_num;
    int time;
    u_int64_t death_time;
    u_int64_t eat_time;
    u_int64_t sleep_time;
    int all_ate;
    int meals_nb;
    int dead;
    int finished;
    pthread_mutex_t write;
    pthread_mutex_t lock;
    int id;
    int num_philo;
    int death_time;
    t_philo *philos;
} t_data;

typedef enum {
    TAKE_R_FORK,
    EATING,
    THINKING,
    SLEEPING
} MessageType;


typedef struct s_philo
{
    int eating;
    int time_to_die;
    int last_meal;
    u_int64_t death_time;
    pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}t_philo;

typedef struct timeval {

    time_t tv_sec;
    suseconds_t tv_usec;
}
void *boringRoutine();

#endif
