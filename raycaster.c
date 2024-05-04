#include "cube3d.h"

// void calculations(t_var *var)
// {
//     int x;
//     double cameraX;
//     //calculate the ray pos and dir
//     var->cameraX = 2 * x / (double)(winWidth) - 1;
//     var->rayDirX = var->dirX + var->planeX * cameraX;
//     var->rayDirY = var->dirY + var->planeY * cameraX;
//     //set the box pos
//     var->mapX = (int)(var->posX);
//     var->mapY = (int)(var->posY);
//     //calc delta position
//     if(var->rayDirX == 0){
//         var->deltaDistX = 1e30;
//     }else{
//         var->deltaDistX = fabs(1 / var->rayDirX);
//     }
//     if(var->rayDirY == 0){
//         var->deltaDistY = 1e30;
//     }else{
//         var->deltaDistY = fabs(1 / var->rayDirY);
//     }
//     //calculate step/side dista X
//     if(var->rayDirX < 0){
//         var->stepX = -1;
//         var->sideDistX = (var->posX - var->mapX) * var->deltaDistX; 
//     }
//     else
//     {
//         var->stepX = 1;
//         var->sideDistX = (var->mapX + 1.0 - var->posX) * var->deltaDistX;
//     }
//     //calculate step/side dista Y
//     if(var->rayDirY < 0)
//     {
//         var->stepY = -1;
//         var->sideDistY = (var->posY - var->mapY) * var->deltaDistY; 
//     }
//     else {
//         var->stepY = 1;
//         var->sideDistY = (var->mapY + 1.0 - var->posY) * var->deltaDistY;
//     }
// }

void draw(t_var *var)
{
    //calculations(var);
    int x = 0;
    double cameraX = 0;
    //calculate the ray pos and dir
    var->cameraX = 2 * x / (double)(winWidth) - 1;
    var->rayDirX = var->dirX + var->planeX * cameraX;
    var->rayDirY = var->dirY + var->planeY * cameraX;
    //set the box pos
    var->mapX = (int)(var->posX);
    var->mapY = (int)(var->posY);
    //calc delta position
    if(var->rayDirX == 0){
        var->deltaDistX = 1e30;
    }else{
        var->deltaDistX = fabs(1 / var->rayDirX);
    }
    if(var->rayDirY == 0){
        var->deltaDistY = 1e30;
    }else{
        var->deltaDistY = fabs(1 / var->rayDirY);
    }
    //calculate step/side dista X
    if(var->rayDirX < 0){
        var->stepX = -1;
        var->sideDistX = (var->posX - var->mapX) * var->deltaDistX; 
    }
    else
    {
        var->stepX = 1;
        var->sideDistX = (var->mapX + 1.0 - var->posX) * var->deltaDistX;
    }
    //calculate step/side dista Y
    if(var->rayDirY < 0)
    {
        var->stepY = -1;
        var->sideDistY = (var->posY - var->mapY) * var->deltaDistY; 
    }
    else {
        var->stepY = 1;
        var->sideDistY = (var->mapY + 1.0 - var->posY) * var->deltaDistY;
    }
    while(var->hit == 0)
    {
        if(var->sideDistX < var->sideDistY)
        {
            var->sideDistX += var->deltaDistX;
            var->mapX += var->stepX;
            var->side = 0;
        }
        else{
            var->sideDistY += var->deltaDistY;
            var->mapY += var->stepY;
            var->side = 1;
        }
        //check if ray has hit the wall
        if(map[var->mapX][var->mapY] > 0)
            var->hit = 0;
    }
    //calculate dist of perpundicular ray
    if(var->side == 0){
        var->perpWallDist = (var->sideDistX - var->deltaDistX);
    }
    else{
        var->perpWallDist = (var->sideDistY - var->deltaDistY);
    }
    //calculate verical line h
    var->lineHeight = (int)(winHeight / var->perpWallDist);
    //calc start/end draw
    var->drawStart = (-1) * var->lineHeight / 2 + winHeight / 2; 
    if(var->drawStart < 0){
        var->drawStart = 0;
    }
    var->drawEnd = var->lineHeight / 2 + winHeight / 2; 
    if(var->drawEnd >= winHeight){
        var->drawEnd = winHeight -  1;
    }
    //calculation textures
    var->texture_num = map[var->mapX][var->mapY] - 1;
    if(var->side == 0)
    {
        var->wallX = var->posY + var->perpWallDist * var->rayDirY;
    }
    else
    {
        var->wallX = var->posX + var->perpWallDist * var->rayDirX;
    }
    var->wallX -= floor(var->wallX);
    //calculate the texture x
    var->texture_x = (int)(var->wallX * (double)(textureHeight));
    if(var->side == 0 && var->rayDirX > 0){
        var->texture_x = textureWidth - var->texture_x  - 1;
    }
    if(var->side == 1 && var->rayDirY < 0){
        var->texture_x = textureWidth - var->texture_x  - 1;
    }
    var->step = 1.0 * textureHeight  / var->lineHeight;
    var->texture_pos = (var->drawStart - winHeight / 2 + var->lineHeight / 2) * var->step;
    int y = var->drawStart;
    while(y< var->drawStart){
        var->texture_y = (int)var->texture_pos & (textureHeight - 1);
        var->texture_pos += var->step;
        var->color = var->texture[var->texture_num][textureHeight * var->texture_y + var->texture_x];
        if(var->side == 1){
            var->color = (var->color >> 1) & 8355711;
        }
       mlx_pixel_put(var->mlx, var->win, x, y, var->color);
        y++;
    }
}

// void movePlayer(){
//     if (keyDown(UP))
//     {
//       if(Map[(int)(posX + dirX * moveSpeed)][(int)(posY)] == false){ 
//             posX += dirX * moveSpeed;
//       }
//       if(Map[(int)(posX)][(int)(posY + dirY * moveSpeed)] == false){
//             posY += dirY * moveSpeed;
//       }
//     }
//     //move backwards if no wall behind you
//     if (keyDown(DOWN))
//     {
//       if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//     }
//     //rotate to the right
//     if (keyDown(SDLK_RIGHT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//       dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//       planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//     }
//     //rotate to the left
//     if (keyDown(SDLK_LEFT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//       dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//       planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//     }
// }

// void raycaster()
// {
//     int x;
//     t_var *var;

//     x = 0;
//     while(x < winHeight){
//         /*calculate the rayPos and direction
//         set the box pos
//         calc delta distance
//         calc step/side distance x and the same with y
//         implememt the dda algorithm
//         calculate the distance of perpendicular ray
//         calculate the verical line height
//         calculate draw start/end
//         calc the texture x
//         draw vertical texture strip*/
//         dda_algo(var);

//         x++;
//     }
// }

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
        draw(var);
    }
    mlx_loop(var->mlx);
    return (0);
}