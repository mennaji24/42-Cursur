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
#define ONE_OR_MORE_ARGS "Error: one or more arguments"
#define ERROR_TIME "gettimeofday() FAILURE"

typedef enum 
{
    TAKE_R_FORK,
    TAKE_L_FORK;
    EATING,
    THINKING,
    SLEEPING
} MessageType;

typedef struct
{
    u_int64_t time_to_die;
    u_int64_t last_meal;
    u_int64_t philo_num;
    u_int64_t time;
    u_int64_t id;
    u_int64_t death_time;
    u_int64_t eat_time;
    u_int64_t sleep_time;
    int all_ate;
    int meals_nb;
    int dead;
    int finished;
    pthread_mutex_t write;
    pthread_mutex_t lock;
    int num_philo;
    int fork;
    t_philo *philos;

} t_data;

typedef struct s_philo
{
    int eat_count;
    int eating;
    u_int64_t death_time;
    pthread_mutex_t	*lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
    t_data *data;

}t_philo;

int	error(char *str, t_data *data);
void check_death_philo(void *arg);
void  *p_thread(void *arg);
void destroy_process(t_data *data);
int process(t_data *data);
void message(MessageType, t_philo *philo);
int get_time(void);
void time_to_eat(t_philo *philo);
int time_to_sleep(suseconds_t time);
void *philo_take_fork(t_philo *philo);
void routine_philosopher(t_philo *philo);
void philos(t_data *data);
int validate_data(t_data *data);
int initialize_data(t_data *data, char **argv, int argc);
int forks(t_data *data);
int init_result(t_data *data, char **argv, int argc);
int	ft_atoi(const char *s);
int allocate_memory(t_data *data);
void free_memory(t_data *data);


#endif
