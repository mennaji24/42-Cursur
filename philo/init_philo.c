#include "philo.h"

int allocate_memory(t_data *data) {
    // Allocate memory for thread IDs
    data->id = malloc(sizeof(pthread_t) * data->philo_num);
    if (!data->id)
        return (error(ALLOC_ERR_1, data));

    // Allocate memory for fork mutexes
    data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
    if (!data->forks)
        return (error(ALLOC_ERR_1, data));

    // Allocate memory for philosopher structures
    data->philos = malloc(sizeof(t_philo) * data->philo_num);
    if (!data->philos)
        return (error(ALLOC_ERR_1, data));

    return (0);
}
void free_memory(t_data *data)
{
     if (data->id != NULL) {
        free(data->id);
        data->id = NULL;
    }
    // Free memory for fork mutexes
    if (data->forks != NULL) {
        free(data->forks);
        data->forks = NULL;
    }
    // Free memory for philosopher structures
    if (data->philos != NULL) {
        free(data->philos);
        data->philos = NULL;
    }
}

void philos(t_data *data)
{
    int i;

    i = 0;
    while(i < data->philo_num)
    {
        // Set the data pointer for each philosopher to the common data structure
        data->philos[i].data = data;

        // Set the philosopher's ID
        data->philos[i].id = i + 1;

        // Set the initial time_to_die to the death_time from the common data structure
        data->philos[i].time_to_die = data->death_time;

        // Initialize other attributes to initial values
        data->philos[i].eat_cont = 0;
        data->philos[i].eating = 0;
        data->philos[i].status = 0;
        pthread_mutex_init(data->philos[i].lock, NULL);
    }
}

int validate_data(t_data *data)
{
    if (data->philo_num <= 0 || data->philo_num > 200 || data->death_time < 0 ||
        data->eat_time < 0 || data->sleep_time < 0){
        return 1;  // Invalid data
    }
    return 0;  // Valid data
}

int initialize_data(t_data *data, char **argv, int argc)
{
    if (argc < 5 || argc > 6)
        return error(ERR_IN_2, NULL);
    data->philo_num = (int)ft_atoi(argv[1]);
    data->death_time = (u_int64_t)ft_atoi(argv[2]);
    data->eat_time = (u_int64_t)ft_atoi(argv[3]);
    data->sleep_time = (u_int64_t)ft_atoi(argv[4]);

    if (argc == 6)
        data->meals_nb = (int)ft_atoi(argv[5]);
    else
        data->meals_nb = -1;
    if (validate_data(data))
        return error(ERR_IN_2, NULL);
    data->dead = 0;
    data->finished = 0;
    //initialize the mutex used to control acess to a shared resources in a multitreading program
    //ensure that one thread can acess a critical section of code
    pthread_mutex_init(&data->write, NULL);
    pthread_mutex_init(&data->lock, NULL);
    return 0;
}

int forks(t_data *data){
    int i;

    i = 0;
    while(i < data->philo_num)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    i = 0;
    while(i < data->philo_num)
    {
        data->philos[i].l_fork = &data->forks[i];
        data->philos[i].r_fork = &data->forks[(i + 1) % data->philo_num];
        i++;
    }
}

int init_result(t_data *data, char **argv, int argc)
{
    if (data(data, argv, argc) != 0)
        return (-1);
    if(allocate_memory(data) != 0)
    {
        free_memory(data);
        return (-1);
    }
    forks(data);
    philos(data);
    return (0);
}