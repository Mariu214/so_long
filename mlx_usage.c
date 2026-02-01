# include "so_long.h"

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
void	render_background(t_img *dest, t_img *src, t_size window)
{
    int	y;
    int	x;

    y = 0;
    while (y < window.height)
    {
        x = 0;
        while (x < window.width)
        {
            put_img_to_img(dest, src, x, y);
            x += src->width;
        }
        y += src->height;
    }
}

int	handle_no_event(void *data)
{
    (void)data;
    return (0);
}

