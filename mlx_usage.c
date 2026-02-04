# include "so_long.h"

int    stopgame(t_data *data)
{
    ft_free(data->tab, data->size.height / 60);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return(0);
}

void    put_img_to_img(t_img *dest, t_img *src, int x_offset, int y_offset)
{
    int x;
    int y;
    int color;
    char *pixel;

    y = 0;
    while (y < src->height)
    {
        x = 0;
        while (x < src->width)
        {
            pixel = src->addr + (y * src->line_len + x * (src->bpp / 8));
            color = *(int *)pixel;
            pixel = dest->addr + ((y + y_offset) * dest->line_len + (x + x_offset) * (dest->bpp / 8));
            *(int *)pixel = color;
            x++;
        }
        y++;
    }
}
void	render_background(t_img *dest, t_img *src, t_data *data)
{
    int	y;
    int	x;

    y = 0;
    while (y < data->size.height)
    {
        x = 0;
        while (x < data->size.width)
        {
            put_img_to_img(dest, src, x, y);
            x += src->width;
        }
        y += src->height;
    }
}

int	handle_no_event(t_data *data)
{
    if (data->victory != 0)
    {
        sleep(3);
        stopgame(data);
    }
    return (0);
}

