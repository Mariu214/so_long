#include "so_long.h"

void    victory(t_data  *data)
{
    if (data->tab[data->pos.height][data->pos.width + 1] == 'E')
    {
        init_asset(data, &data->player, "./textures/player-right_blush.xpm");
        init_asset(data, &data->exit, "./textures/player-left_blush.xpm");
    }
    else 
    {
        init_asset(data, &data->player, "./textures/player-left_blush.xpm");
        init_asset(data, &data->exit, "./textures/player-right_blush.xpm");
    }
    put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
                data->pos.height * 60);
    data->pos.width++;
    put_img_to_img(&data->img, &data->exit, data->position_exit.width * 60, 
                data->position_exit.height * 60);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    data->victory = 1;
}

void    dogs_moves(t_data *data)
{
    int i;

    i = 0;
    if (data->count.P == 0)
    {
        while (i < data->count.D)
        {
            init_asset(data, &data->dog, choose_texture_dog(data));
            if(data->pos.width - data->dogs[i].position.width < 0 
                && data->tab[data->dogs[i].position.height][data->dogs[i].position.width - 1] == '0'
                && !verif_dog_presence(data, data->dogs[i].position.width - 1, data->dogs[i].position.height, i))
            {
                    put_img_to_img(&data->img, &data->background, data->dogs[i].position.width * 60, 
                    data->dogs[i].position.height * 60);
                    data->dogs[i].position.width--;
                    put_img_to_img(&data->img, &data->dog, data->dogs[i].position.width * 60, 
                    data->dogs[i].position.height * 60);
            }
            else if(data->pos.width - data->dogs[i].position.width > 0 
                && data->tab[data->dogs[i].position.height][data->dogs[i].position.width + 1] == '0'
                && !verif_dog_presence(data, data->dogs[i].position.width + 1, data->dogs[i].position.height, i))
            {
                    put_img_to_img(&data->img, &data->background, data->dogs[i].position.width * 60, 
                    data->dogs[i].position.height * 60);
                    data->dogs[i].position.width++;
                    put_img_to_img(&data->img, &data->dog, data->dogs[i].position.width * 60, 
                    data->dogs[i].position.height * 60);
            }
            else if (data->pos.height - data->dogs[i].position.height < 0
                && data->tab[data->dogs[i].position.height - 1][data->dogs[i].position.width] == '0'
                && !verif_dog_presence(data, data->dogs[i].position.width, data->dogs[i].position.height - 1, i))
            {
                put_img_to_img(&data->img, &data->background, data->dogs[i].position.width * 60, 
                data->dogs[i].position.height * 60);
                data->dogs[i].position.height--;
                put_img_to_img(&data->img, &data->dog, data->dogs[i].position.width * 60, 
                data->dogs[i].position.height * 60);
            }
            else if (data->pos.height - data->dogs[i].position.height > 0
                && data->tab[data->dogs[i].position.height + 1][data->dogs[i].position.width] == '0'
                && !verif_dog_presence(data, data->dogs[i].position.width, data->dogs[i].position.height + 1, i))
            {
                put_img_to_img(&data->img, &data->background, data->dogs[i].position.width * 60, 
                data->dogs[i].position.height * 60);
                data->dogs[i].position.height++;
                put_img_to_img(&data->img, &data->dog, data->dogs[i].position.width * 60, 
                data->dogs[i].position.height * 60);
            }
            i++;
        }
        data->count.P += 2;
    }
    data->count.P -= 1;
}

int verif_dog_presence(t_data *data, int x, int y, int i)
{
    int j;

    j = 0;
    while(j < data->count.D)
    {
        if (i != j && data->dogs[j].position.width == x
            && data->dogs[j].position.height == y)
            return(1);
        j++;
    }
    return(0);
}

void    defeat(t_data  *data)
{
    init_asset(data, &data->player, "./textures/dog_lost.xpm");
    put_img_to_img(&data->img, &data->player, data->pos.width * 60, 
                data->pos.height * 60);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    data->victory = 1;
}

char *choose_texture_dog(t_data *data)
{
    if (data->size.width == 0)
        return(data->size.width++, "./textures/dog/dog_1.xpm");
    if (data->size.width == 1)
        return(data->size.width++, "./textures/dog/dog_2.xpm");
    if (data->size.width == 2)
        return(data->size.width++, "./textures/dog/dog_3.xpm");
    if (data->size.width == 3)
        return(data->size.width++, "./textures/dog/dog_4.xpm");
    if (data->size.width == 4)
        return(data->size.width++, "./textures/dog/dog_5.xpm");
    if (data->size.width == 5)
        return(data->size.width++, "./textures/dog/dog_6.xpm");
    if (data->size.width == 6)
        return(data->size.width++, "./textures/dog/dog_7.xpm");
    if (data->size.width == 7)
        return(data->size.width++, "./textures/dog/dog_8.xpm");
    if (data->size.width == 8)
        return(data->size.width++, "./textures/dog/dog_9.xpm");
    if (data->size.width == 9)
        return(data->size.width = 0, "./textures/dog/dog_10.xpm");
    return(0);
}



