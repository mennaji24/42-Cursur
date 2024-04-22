#ifndef CUBE3D_H
#define CUBE3D_H

#define winWidth 640
#define winHeight 480
#define mapWidth 24
#define mapHeight 24

typedef struct {
    int worldMap[mapWidth][mapHeight];
} World;

typedef struct {
    float posX;
    float posY;
    float dirX;
    float dirY;
    float planeX;
    float planeY;
    float cameraX;
    float rayDirX;
    float rayDirY;
    float sideDistX;
    float sideDistY;
    float deltaDistX;
    float deltaDistY;
    float perpWallDist;
    int stepX;
    int stepY;
    int side;
    int lineHeight;
    int drawStart;
    int drawEnd;
} Player;

typedef struct 
{
    int mapX;
    int mapY;
    int hit;
} RaycastInfo;

void draw_vertical_line(int x, int drawStart, int drawEnd, int color, void *mlx, void *win);
void init_player(Player *player, float posX, float posY, float dirX, float dirY, float planeX, float planeY);
void init_raycast_info(RaycastInfo *raycastInfo, int mapX, int mapY);
void cast_rays(Player *player, World *world, int winWidth, int winHeight, void *mlx, void *win);
void cast_single_ray(Player *player, World *world, int x);
void calculate_side_distances(Player *player, RaycastInfo *raycastInfo);
void perform_dda(Player *player, RaycastInfo *raycastInfo, World *world);
void calculate_perp_wall_dist(Player *player, RaycastInfo *raycastInfo);
void calculate_wall_height(Player *player, int winHeight);
void draw_wall_slice(Player *player, World *world, RaycastInfo *raycastInfo, void *mlx, void *win);

#endif
