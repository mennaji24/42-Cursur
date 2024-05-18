#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/time.h>
#include <unistd.h>
#include "mlx_linux/mlx.h"

#define mapWidth 24
#define mapHeight 24
#define winWidth 640
#define winHeight 480

typedef struct {
    int red;
    int green;
    int blue;
} ColorRGB;

typedef struct {
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double moveSpeed;
    double rotSpeed;
} t_game;

t_game game = {
    .posX = 22,
    .posY = 12,
    .dirX = -1,
    .dirY = 0,
    .planeX = 0,
    .planeY = 0.66,
    .moveSpeed = 0.05,  // Adjusted for better control
    .rotSpeed = 0.03    // Adjusted for better control
};

#define RGB_Red     ((ColorRGB){255, 0, 0})
#define RGB_Green   ((ColorRGB){0, 255, 0})
#define RGB_Blue    ((ColorRGB){0, 0, 255})
#define RGB_White   ((ColorRGB){255, 255, 255})
#define RGB_Yellow  ((ColorRGB){255, 255, 0})


int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


size_t	ft_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_len(nb);
	str = malloc(sizeof(char) * (1 + len));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}


void drawVerLine(void *mlx_ptr, void *win_ptr, int x, int drawStart, int drawEnd, ColorRGB color){
    int y = drawStart;
    while(y <= drawEnd){
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, (color.red << 16) + (color.green << 8) + color.blue);
        y++;
    }
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(u_int64_t time)
{
	u_int64_t	start;

	start = 0;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == 65362) // Up key
    {
        if (worldMap[(int)(game->posX + game->dirX * game->moveSpeed)][(int)(game->posY)] == 0)
            game->posX += game->dirX * game->moveSpeed;
        if (worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * game->moveSpeed)] == 0)
            game->posY += game->dirY * game->moveSpeed;
    }
    if (keycode == 65364) // Down key
    {
        if (worldMap[(int)(game->posX - game->dirX * game->moveSpeed)][(int)(game->posY)] == 0)
            game->posX -= game->dirX * game->moveSpeed;
        if (worldMap[(int)(game->posX)][(int)(game->posY - game->dirY * game->moveSpeed)] == 0)
            game->posY -= game->dirY * game->moveSpeed;
    }
    if (keycode == 65363) // Right key
    {
        double oldDirX = game->dirX;
        game->dirX = game->dirX * cos(-game->rotSpeed) - game->dirY * sin(-game->rotSpeed);
        game->dirY = oldDirX * sin(-game->rotSpeed) + game->dirY * cos(-game->rotSpeed);
        double oldPlaneX = game->planeX;
        game->planeX = game->planeX * cos(-game->rotSpeed) - game->planeY * sin(-game->rotSpeed);
        game->planeY = oldPlaneX * sin(-game->rotSpeed) + game->planeY * cos(-game->rotSpeed);
    }
    if (keycode == 65361) // Left key
    {
        double oldDirX = game->dirX;
        game->dirX = game->dirX * cos(game->rotSpeed) - game->dirY * sin(game->rotSpeed);
        game->dirY = oldDirX * sin(game->rotSpeed) + game->dirY * cos(game->rotSpeed);
        double oldPlaneX = game->planeX;
        game->planeX = game->planeX * cos(game->rotSpeed) - game->planeY * sin(game->rotSpeed);
        game->planeY = oldPlaneX * sin(game->rotSpeed) + game->planeY * cos(game->rotSpeed);
    }
    return 0;
}


int main()
{
    void *mlx_ptr;
    void *win_ptr;
    double time = 0; //time of current frame
    double old_time = 0; //time of previous frame
    double	frame_time;
    int		frame_per_second;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, winWidth, winHeight, "Cube");
    mlx_key_hook(win_ptr, key_hook, &game);
    while(1)
    {
        int x = 0;
        mlx_clear_window(mlx_ptr, win_ptr);
        while(x++ < winWidth)
        {
            double cameraX = 2 * x / (double)winWidth - 1; //x-coordinate in camera space
            double rayDirX = game.dirX + game.planeX * cameraX;
            double rayDirY = game.dirY + game.planeY * cameraX;

            int mapX = (int)game.posX;
            int mapY = (int)game.posY;

            double sideDistX;
            double sideDistY;
            double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
            double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
            double perpWallDist;
            //what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;

            int hit = 0; //was there a wall hit?
            int side; //was a NS or a EW wall hit?
             //calculate step and initial sideDist
            if (rayDirX < 0)
            {
            stepX = -1;
            sideDistX = (game.posX - mapX) * deltaDistX;
            }
            else
            {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game.posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
            stepY = -1;
            sideDistY = (game.posY - mapY) * deltaDistY;
            }
            else
            {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game.posY) * deltaDistY;
            }
            while (hit == 0)
            {
                //jump to next map square, either in x-direction, or in y-direction
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                //Check if ray has hit a wall
                if (worldMap[mapX][mapY] > 0){
                    hit = 1;
                }
                if(side == 0){
                    perpWallDist = (sideDistX - deltaDistX);
                }
                else{
                    perpWallDist = (sideDistY - deltaDistY);
                }
                int lineHeight = (int)(winHeight / perpWallDist);
                int drawStart = (-1) * lineHeight / 2 + winHeight / 2;
                if(drawStart < 0){
                    drawStart = 0;
                }
                int drawEnd = lineHeight / 2 + winHeight / 2;
                if(drawEnd >= winHeight){
                    drawEnd = winHeight - 1;
                }
                ColorRGB color;
                int mapValue = worldMap[mapX][mapY];
                if (mapValue == 1)
                    color = RGB_Red;
                else if (mapValue == 2)
                    color = RGB_Green;
                else if (mapValue == 3)
                    color = RGB_Blue;
                else if (mapValue == 4)
                    color = RGB_White;
                else
                    color = RGB_Yellow;
                
                if (side == 1)
                {
                    color.red /= 2;
                    color.green /= 2;
                    color.blue /= 2;
                }
                drawVerLine(mlx_ptr, win_ptr, x, drawStart, drawEnd, color);
            }
            // Calculate frame time, FPS, move speed, and rotation speed
            old_time = time;
            time = get_time();
            frame_time = (time - old_time) / 1000.0;
            frame_per_second = (int)(1.0 / frame_time);
            if (frame_per_second > 60) {
                ft_sleep(((1.0 / 60) - frame_time) * 1000);
                time = get_time();
                frame_time = (time - old_time) / 1000.0;
                frame_per_second = (int)(1.0 / frame_time);
            }
            game.moveSpeed = frame_time * 5.0;
            game.rotSpeed = frame_time * 3.0;

            // Display FPS on the screen
            char *fps_str = ft_itoa(frame_per_second);
            if (fps_str) {
                mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF, fps_str);
                free(fps_str);
            }
        }
    }
    return(0);

}