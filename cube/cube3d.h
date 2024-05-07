#ifndef CUBE3D_H
#define CUBE3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>
#include "mlx_linux/mlx.h"

#define winWidth 1000
#define winHeight 1500
#define textureHeight 64
#define textureWidth 64
#define UP
#define DOWN
#define RIGHT
#define LEFT
# define BLUE       0x10069F
# define RED        0xEF3340
#define COLOR(r, g, b) (((r) << 16) | ((g) << 8) | (b))

int map[winWidth][winHeight] = 
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_var
{
    void *mlx;
    void *win;
    char **map;
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
    int texture_y;
    int step;
    int texture_pos;
    int color;
    int texture[4][textureHeight * textureWidth];
    double moveSpeed;
    double rotSpeed;


}           t_var;

void calculate_ray_dir(t_var *var, double cameraX);
void draw(t_var *var);
#endif