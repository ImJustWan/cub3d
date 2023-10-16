#include "wonderland.h"

int    clean_init(t_world *world)
{
    world->mlx_ptr = NULL;
    world->win = NULL;
    world->time = 0;
    world->old_time = 0;
    world->map = NULL;
    world->img = malloc(sizeof(t_img));
    if (!world->img)
        return (1);
    world->ray = malloc(sizeof(t_raycast));
    if (!world->ray)
        return (1);
    world->setup = malloc(sizeof(t_setup));
    if (!world->setup)
        return (1);
    world->player = malloc(sizeof(t_player));
    if (!world->player)
        return (1);
    return (0);
}
