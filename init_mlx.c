# include "so_long.h"


void    init_asset(t_data *data, t_img *asset, char *path)
{
    asset->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &asset->width, &asset->height);
    if (!asset->mlx_img)
        exit (1);
    asset->addr = mlx_get_data_addr(asset->mlx_img, &asset->bpp, &asset->line_len, &asset->endian);
}

void    init_data(t_data *data, t_size window)
{
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, window.width, window.height);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
    init_asset(data, &data->bone, "./textures/Bone.xpm");
    init_asset(data, &data->background, "./textures/background-tile.xpm");
    init_asset(data, &data->wall, "./textures/tree.xpm");
    init_asset(data, &data->player, "./textures/player-idle.xpm");
    init_asset(data, &data->exit, "./textures/Bone-head.xpm");
}

void    draw_map(char **tab, t_data *data, t_size window)
{
    int y;
    int x;

    y = 0;
    render_background(&data->img, &data->background, window);
    if (data->win_ptr == NULL)
        exit (1);
    while (tab[y])
    {
        x = 0;
        while (tab[y][x])
        {
            if (tab[y][x] == '1')
                put_img_to_img(&data->img, &data->wall, x * 60, y * 60);
            else if (tab[y][x] == 'P')
            {
                put_img_to_img(&data->img, &data->player, x * 60, y * 60);
                data->pos.width = x;
                data->pos.height = y;
            }
            else if (tab[y][x] == 'E')
                put_img_to_img(&data->img, &data->exit, x * 60, y * 60);
            else if (tab[y][x] == 'C')
                put_img_to_img(&data->img, &data->bone, x * 60, y * 60);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}

void so_long(char **tab, t_size size, t_count count)
{
    t_data  data;
    int     i;
    t_size  window;

    window.width = size.width * 60;
    window.height = size.height * 60;
    i = 0;
    data.acquired = 0;
    data.objective = count.C;
    printf("%d%d%d\n", count.C, data.objective, data.acquired);
    data.tab = ft_superdup(tab, size);
    while(data.tab[i])
	{
		printf("%s\n", data.tab[i]);
		i++;
	}
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        exit (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, window.width, window.height, "My first window!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        exit (1);
    }
    init_data(&data, window);
    draw_map(tab, &data, window);

    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &press_input, &data);

    mlx_loop(data.mlx_ptr);

    mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}


