#include "philo.h"


int	ft_atoi(const char *s)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		value *= 10;
		value += *s - 48;
		s++;
	}
	return (value * sign);
}

int allocate_memory(t_data *data)
{
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