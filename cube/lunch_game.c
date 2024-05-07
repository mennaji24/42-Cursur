#include "cube3d.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drawFloor(void)
{
    t_data *data;
    t_var *var;
    int i = 0;

    while(i < winWidth)
    {
        int j = winHeight / 2;
        while(j < winHeight){
            if(i >= 0 && i < winWidth && j >= 0 && j < winHeight)
                my_mlx_pixel_put(data, i, j, RED);
            j++;
        }
        i++;
    }
}

void drawCeiling(void)
{
    t_data *data;
    t_var *var;
    int i = 0;

    while(i < winWidth)
    {
        int j = winHeight / 2;
        while(j < winHeight){
            if(i >= 0 && i < winWidth && j >= 0 && j < winHeight)
                my_mlx_pixel_put(data, i, j, BLUE);
            j++;
        }
        i++;
    }
}

void raycaster()
{
    int x;
    t_var *var;

    x = 0;
    while(x < winHeight){
        /*calculate the rayPos and direction
        set the box pos
        calc delta distance
        calc step/side distance x and the same with y
        implememt the dda algorithm
        calculate the distance of perpendicular ray
        calculate the verical line height
        calculate draw start/end
        calc the texture x
        draw vertical texture strip*/
        draw(var);

        x++;
    }
}

void key_hook()
{
    t_var *var; 

    if (keyDown(UP))
    {
      if(map[(int)(var->posX + var->dirX * var->moveSpeed)][(int)(var->posY)] == false){ 
            var->posX += var->dirX * var->moveSpeed;
      }
      if(map[(int)(var->posX)][(int)(var->posY + var->dirY * var->moveSpeed)] == false){
            var->posY += var->dirY * var->moveSpeed;
      }
    }
    //move backwards if no wall behind you
    if (keyDown(DOWN))
    {
      if(map[(int)(var->posX - var->dirX * var->moveSpeed)][(int)(var->posY)] == false) 
            var->posX -= var->dirX * var->moveSpeed;
      if(map[(int)(var->posX)][(int)(var->posY - var->dirY * var->moveSpeed)] == false) 
            var->posY -= var->dirY * var->moveSpeed;
    }
    //rotate to the right
    if (keyDown(RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = var->dirX;
      var->dirX = var->dirX * cos((-1) * var->rotSpeed) - var->dirY * sin((-1) * var->rotSpeed);
      var->dirY = oldDirX * sin((-1) * var->rotSpeed) + var->dirY * cos((-1) * var->rotSpeed);
      double oldPlaneX = var->planeX;
      var->planeX = var->planeX * cos((-1) * var->rotSpeed) - var->planeY * sin((-1) * var->rotSpeed);
      var->planeY = oldPlaneX * sin((-1) * var->rotSpeed) + var->planeY * cos((-1) * var->rotSpeed);
    }
    //rotate to the left
    if (keyDown(LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = var->dirX;
      var->dirX = var->dirX * cos(var->rotSpeed) - var->dirY * sin(var->rotSpeed);
      var->dirY = oldDirX * sin(var->rotSpeed) + var->dirY * cos(var->rotSpeed);
      double oldPlaneX = var->planeX;
      var->planeX = var->planeX * cos(var->rotSpeed) - var->planeY * sin(var->rotSpeed);
      var->planeY = oldPlaneX * sin(var->rotSpeed) + var->planeY * cos(var->rotSpeed);
    }
}

int cube(void)
{
    void *img;
    char *addr;
    t_var *var;
    t_data *data;

    img = mlx_new_image(var->mlx, winWidth, winHeight);
    addr = mlx_get_data_addr(img, data->bits_per_pixel, data->line_length, data->endian);
    drawFloor();
    drawCeiling();
    raycaster();
    key_hook();


}

