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
    int last_meal;
    int r_fork;
    int l_fork;
    struct s_data *data;
    pthread_t thread_nbr;

}t_philo;

typedef struct s_data
{
    int eat;
    int first_time;
    int philo_nbr;
    int time_death;
    int time_eat;
    int time_sleep;
    int meal_nbr;
    int died;
    int all_ate;
    pthread_mutex_t meal_check;
    pthread_mutex_t forks[250];
    pthread_mutex_t write;
    t_philo *philos;
}t_data;


int init_mutex(t_data *data);
int init_philos(t_data *data);
int initialize_data(t_data *data, char **av);
void eat(t_philo *philo);
void *action(void *void_argv);
void quit(t_data *data, t_philo *philos);
void check_death(t_data *p, t_philo *phi);
int thread(t_data *data);
int	ft_atoi(const char *s);
int validate_data(t_data *data);
long long	get_time(void);
void ft_sleep(long long duration, t_data *data);
void print_message(t_data *data, int nbr, char *str);
long long	time_delta(long long past, long long pres);
#endif