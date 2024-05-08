#include "cube3d.h"
void wallCasting()
{
    int y = 0;
    t_var *var;

    while(y < winHeight){
      float rayDirX0 = var->dirX - var->planeX;
      float rayDirY0 = var->dirY - var->planeY;
      float rayDirX1 = var->dirX + var->planeX;
      float rayDirY1 = var->dirY + var->planeY;
    }
}

void calcRayPosDirection(int x)
{
    double cameraX;
    t_var *var;
    //calculate the ray pos and dir
    var->cameraX = 2 * x / (double)(winWidth) - 1;
    var->rayDirX = var->dirX + var->planeX * cameraX;
    var->rayDirY = var->dirY + var->planeY * cameraX;
    //set the box pos
    var->mapX = (int)(var->posX);
    var->mapY = (int)(var->posY);
}

void CalcDeltaDistance()
{
    t_var *var;

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
}

void calcSideStepDistXY(void)
{   
    t_var *var;

    if(var->rayDirX < 0)
    {
        var->stepX = -1;
        var->sideDistX = (var->posX - var->mapX) * var->deltaDistX; 
    }
    else
    {
        var->stepX = 1;
        var->sideDistX = (var->mapX + 1.0 - var->posX) * var->deltaDistX;
    }
    if(var->rayDirY < 0)
    {
        var->stepY = -1;
        var->sideDistY = (var->posY - var->mapY) * var->deltaDistY; 
    }
    else {
        var->stepY = 1;
        var->sideDistY = (var->mapY + 1.0 - var->posY) * var->deltaDistY;
    }
}

void dda_algo()
{
    t_var *var;
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
        if(map[var->mapX][var->mapY] > 0){
            var->hit = 0;
            setTexture();
        }

    }
}

void screenCalculation()
{
    t_var *var;
    //CALCULUTE THE DIST PERPENDUCULAR RAY
    if(var->side == 0){
        var->perpWallDist = (var->sideDistX - var->deltaDistX);
    }
    else{
        var->perpWallDist = (var->sideDistY - var->deltaDistY);
    }
    //CALCULATE THE VERITICALE HEIGHT
    var->lineHeight = (int)(winHeight / var->perpWallDist);
    //CALCULATE DRAW START AND END
    var->drawStart = (-1) * var->lineHeight / 2 + winHeight / 2; 
    if(var->drawStart < 0){
        var->drawStart = 0;
    }
    var->drawEnd = var->lineHeight / 2 + winHeight / 2; 
    if(var->drawEnd >= winHeight){
        var->drawEnd = winHeight -  1;
    }
}

void calcTextureX(void)
{   
    t_var *var;

    if(var->side == 0)
    {
        var->wallX = var->posY + var->perpWallDist * var->rayDirY;
    }
    else
    {
        var->wallX = var->posX + var->perpWallDist * var->rayDirX;
    }
    var->wallX -= floor(var->wallX);
    var->texture_x = (int)(var->wallX * (double)(textureHeight));
    if(var->side == 0 && var->rayDirX > 0){
        var->texture_x = textureWidth - var->texture_x  - 1;
    }
    if(var->side == 1 && var->rayDirY < 0){
        var->texture_x = textureWidth - var->texture_x  - 1;
    }
}

//DRAW THE VERICAL TEXTURE STRIPE
void calcVerticalTexture(int x)
{
    t_var *var;
    int y;
    double texture_pos;

    var->step = 1.0 * textureHeight  / var->lineHeight;
    texture_pos = (var->drawStart - winHeight / 2 + var->lineHeight / 2) * var->step;
    y = var->drawStart;
    while(y < var->drawStart)
    {
        var->texture_y = (int)texture_pos & (textureHeight - 1);
        texture_pos += var->step;
        var->color = var->texture[var->texture_num][textureHeight * var->texture_y + var->texture_x];
        if(var->side == 1){
            var->color = (var->color >> 1) & 8355711;
        }
        my_mlx_pixel_put(x, y, var->color);
        y++;
    }
}

// function iterates over each column of pixels in the window width
void renderScene()
{
    int x = 0;
    while (x < winWidth)
    {
        calcRayPosDirection(x);
        CalcDeltaDistance();
        calcSideStepDistXY();
        dda_algo();
        screenCalculation();//map screen calculation
        calcTextureX();
        calcVerticalTexture(x);
        x++;
    }
}