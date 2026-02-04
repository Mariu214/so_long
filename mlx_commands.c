# include "so_long.h"

void    go_up(t_data *data)
{
    if (data->tab[data->pos.height - 1][data->pos.width] == '0')
    {
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.height--;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height - 1][data->pos.width] == 'C')
    {
        data->acquired++;
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.height--;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height - 1][data->pos.width] == 'E')
        if (data->acquired == data->count.C)
            victory(data);
    data->tab[data->pos.height + 1][data->pos.width] = '0';
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    dogs_moves(data);
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    printf("%d\n", data->count.E++);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}

void    go_down(t_data *data)
{
    if (data->tab[data->pos.height + 1][data->pos.width] == '0')
    {
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.height++;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height + 1][data->pos.width] == 'C')
    {
        data->acquired++;
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.height++;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height + 1][data->pos.width] == 'E')
        if (data->acquired == data->count.C)
            victory(data);
    data->tab[data->pos.height - 1][data->pos.width] = '0';
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    dogs_moves(data);
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    printf("%d\n", data->count.E++);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}

void    go_left(t_data *data)
{
    if (data->acquired > 0)
        init_asset(data, &data->player, "./textures/player-bone-left.xpm");
    else 
        init_asset(data, &data->player, "./textures/player-left.xpm");
    if (data->tab[data->pos.height][data->pos.width - 1] == '0')
    {
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.width--;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height][data->pos.width - 1] == 'C')
    {
        data->acquired++;
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.width--;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height][data->pos.width - 1] == 'E')
        if (data->acquired == data->count.C)
            victory(data);
    data->tab[data->pos.height][data->pos.width + 1] = '0';
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    dogs_moves(data);
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    printf("%d\n", data->count.E++);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}
void    go_right(t_data *data)
{
    if (data->acquired > 0)
        init_asset(data, &data->player, "./textures/player-bone-right.xpm");
    else 
        init_asset(data, &data->player, "./textures/player-right.xpm");
    if (data->tab[data->pos.height][data->pos.width + 1] == '0')
    {
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.width++;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height][data->pos.width + 1] == 'C')
    {
        data->acquired++;
        put_img_to_img(&data->img, &data->background, data->pos.width * 60, 
            data->pos.height * 60);
        data->pos.width++;
        put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
            data->pos.height * 60);
    }
    else if (data->tab[data->pos.height][data->pos.width + 1] == 'E')
        if (data->acquired == data->count.C)
            victory(data);
    data->tab[data->pos.height][data->pos.width - 1] = '0';
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    dogs_moves(data);
    if (verif_dog_presence(data, data->pos.width, data->pos.height, -1))
        defeat(data);
    printf("%d\n", data->count.E++);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}


int press_input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        stopgame(data);
    if (data->victory == 0)
    {
        if (keysym == XK_Up)
            if (data->tab[data->pos.height - 1][data->pos.width] != '1')
                go_up(data);
        if (keysym == XK_Down)
            if (data->tab[data->pos.height + 1][data->pos.width] != '1')
                go_down(data);
        if (keysym == XK_Left)
            if (data->tab[data->pos.height][data->pos.width - 1] != '1')
                go_left(data);
        if (keysym == XK_Right)
            if (data->tab[data->pos.height][data->pos.width + 1] != '1')
                go_right(data);
    }
    return (0);
}
