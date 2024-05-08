#include "cube3d.h"

int main(/*int argc, char **argv*/)
{
    t_var *var;

    var = malloc(sizeof(t_var));
    if(!var){
        printf("Failed to allocate memory for var\n");
        return 1;
    }
    var->mlx = mlx_init();
    if(!var->mlx){
        printf("Failed to initialize MiniLibX\n");
        free(var); // Free memory allocated for var
        return 1; // Return an error code
    }
    var->win = mlx_new_window(var->mlx, winWidth, winHeight, "Cube3d");
    if (!var->win) {
        printf("Failed to create a new window\n");
        mlx_destroy_display(var->mlx); // Cleanup MiniLibX resources
        free(var); // Free memory allocated for var
        return 1; // Return an error code
    }
    while(1)
    {
         //mlx_clear_window(mlx, win);
        cube();
    }
    mlx_loop(var->mlx);
    return (0);
}