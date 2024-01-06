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

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));

}

/*void ft_sleep(long long duration, t_data *data)
{
    long long start_time =  get_time();
    while(!(data->died) && (get_time() - start_time) < duration)
        usleep(50);
}*/

long long	time_delta(long long past, long long pres)
{
	return (pres - past);
}

void	ft_sleep(long long time, t_data *data)
{
	long long	i;

	i = get_time();
	while (!(data->died))
	{
		if (time_delta(i, get_time()) >= time)
			break ;
		usleep(50);
	}
}

void print_message(t_data *data, int nbr, char *str)
{
	pthread_mutex_lock(&(data->write));
	if(!(data->died))
	{
		printf("\033[32m%lli\033[0m ", get_time() - data->first_time);
        printf("\033[32m%i\033[0m ", nbr + 1);
        printf("\033[0m%s\033[0m\n", str);
	}
	 pthread_mutex_unlock(&(data->write));
	 return;
}