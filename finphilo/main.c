#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    int check;

    if(argc != 5 && argc != 6)
        return (-1);
    check = initialize_data(&data, argv);
    if(!check)
        return (1);
    if(thread(data)){
        printf("Failed to create the threads\n");
        return(1);
    }
    return(0);
}