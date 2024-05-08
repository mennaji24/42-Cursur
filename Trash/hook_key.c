#include "cube3d.h"

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