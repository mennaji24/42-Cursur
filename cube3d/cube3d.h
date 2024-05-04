#ifndef CUBE3D_H
#define CUBE3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define winWidth 1000
#define winHeight 1500
#define textureHeight 64
#define textureWidth 64


typedef struct s_var
{
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double time;
    double oldTime;
    double cameraX;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    double deltaDistX;
    double deltaDistY;
    double sideDistX;
    double sideDistY;
    int stepX;
    int stepY;
    int hit;
    int side;
    double perpWallDist;
    double drawStart;
    double drawEnd;
    int lineHeight;
    int texture_num;
    double wallX;
    double posX;
    double posY;
    int  texture_x;
    int step;


}           t_var;

void calculate_ray_dir(t_point *points, t_var *var, double cameraX);

#endif