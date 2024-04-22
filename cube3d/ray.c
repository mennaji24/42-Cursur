#include "cube3d.h"
#include "mlx.h"

void draw_vertical_line(int x, int drawStart, int drawEnd, int color, void *mlx, void *win) 
{
    int y;
    for (y = drawStart; y <= drawEnd; y++)
        mlx_pixel_put(mlx, win, x, y, color);
}

void init_player(Player *player, float posX, float posY, float dirX, float dirY, float planeX, float planeY)
 {
    player->posX = posX;
    player->posY = posY;
    player->dirX = dirX;
    player->dirY = dirY;
    player->planeX = planeX;
    player->planeY = planeY;
}

void init_raycast_info(RaycastInfo *raycastInfo, int mapX, int mapY) 
{
    raycastInfo->mapX = mapX;
    raycastInfo->mapY = mapY;
    raycastInfo->hit = 0;
}

void cast_rays(Player *player, World *world, int winWidth, int winHeight, void *mlx, void *win) 
{
    int x;

    x = 0;
    while(x < winWidth)
    {
        cast_single_ray(player, world, x);
        calculate_wall_height(player, winHeight);
        draw_wall_slice(player, world, mlx, win);
        x++;
    }

}

void cast_single_ray(Player *player, World *world, int x) 
{
    player->cameraX = 2 * x / (float)winWidth - 1;
    player->rayDirX = player->dirX + player->planeX * player->cameraX;
    player->rayDirY = player->dirY + player->planeY * player->cameraX;

    // Initialize raycast info
    RaycastInfo raycastInfo;
    init_raycast_info(&raycastInfo, (int)player->posX, (int)player->posY);

    calculate_side_distances(player, &raycastInfo);
    perform_dda(player, &raycastInfo, world);
    calculate_perp_wall_dist(player, &raycastInfo);
}

void calculate_side_distances(Player *player, RaycastInfo *raycastInfo)
{
    player->deltaDistX = ft_abs(1 / player->rayDirX);
    player->deltaDistY = ft_abs(1 / player->rayDirY);

    if (player->rayDirX < 0) 
    {
        player->stepX = -1;
        player->sideDistX = (player->posX - raycastInfo->mapX) * player->deltaDistX;
    } else 
    {
        player->stepX = 1;
        player->sideDistX = (raycastInfo->mapX + 1.0 - player->posX) * player->deltaDistX;
    }

    if (player->rayDirY < 0) 
    {
        player->stepY = -1;
        player->sideDistY = (player->posY - raycastInfo->mapY) * player->deltaDistY;
    } else 
    {
        player->stepY = 1;
        player->sideDistY = (raycastInfo->mapY + 1.0 - player->posY) * player->deltaDistY;
    }
}

void perform_dda(Player *player, RaycastInfo *raycastInfo, World *world) 
{
    while (raycastInfo->hit == 0) 
    {
        if (player->sideDistX < player->sideDistY) 
        {
            player->sideDistX += player->deltaDistX;
            raycastInfo->mapX += player->stepX;
            player->side = 0;
        } else {
            player->sideDistY += player->deltaDistY;
            raycastInfo->mapY += player->stepY;
            player->side = 1;
        }
        if (world->worldMap[raycastInfo->mapX][raycastInfo->mapY] > 0) {
            raycastInfo->hit = 1;
        }
    }
}

void calculate_perp_wall_dist(Player *player, RaycastInfo *raycastInfo)
{
    if (player->side == 0) {
        player->perpWallDist = (raycastInfo->mapX - player->posX + (1 - player->stepX) / 2) / player->rayDirX;
    } else {
        player->perpWallDist = (raycastInfo->mapY - player->posY + (1 - player->stepY) / 2) / player->rayDirY;
    }
}

void calculate_wall_height(Player *player, int winHeight)
{
    player->lineHeight = (int)(winHeight / player->perpWallDist);
    player->drawStart = -player->lineHeight / 2 + winHeight / 2;
    if (player->drawStart < 0) {
        player->drawStart = 0;
    }
    player->drawEnd = player->lineHeight / 2 + winHeight / 2;
    if (player->drawEnd >= winHeight) {
        player->drawEnd = winHeight - 1;
    }
}

void draw_wall_slice(Player *player, World *world, RaycastInfo *raycastInfo, void *mlx, void *win)
{
    int color;
    int x;

    x =0;
    if (world->worldMap[raycastInfo->mapX][raycastInfo->mapY] == 1) {
        color = 0xFF0000; // red
    } else if (world->worldMap[raycastInfo->mapX][raycastInfo->mapY] == 2) {
        color = 0x00FF00; // green
    } else if (world->worldMap[raycastInfo->mapX][raycastInfo->mapY] == 3) {
        color = 0x0000FF; // blue
    } else if (world->worldMap[raycastInfo->mapX][raycastInfo->mapY] == 4) {
        color = 0xFFFFFF; // white
    } else {
        color = 0xFFFF00; // yellow
    }
    if (player->side == 1) {
        color /= 2;
    }
    draw_vertical_line(x, player->drawStart, player->drawEnd, color, mlx, win);
}


int main(){
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, screenWidth, screenHeight, "Raycaster");
    while(1){
        // Cast rays, draw the scene
        cast_rays(&player, &world, screenWidth, screenHeight, mlx_ptr, win_ptr);

        // Update the window
        mlx_loop(mlx_ptr);
    }
    return (0);
}