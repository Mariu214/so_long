#ifndef SO_LONG_H
# define SO_LONG_H

# include <bsd/string.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

#include <X11/X.h>
#include <X11/keysym.h>
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
#define WHITE_PIXEL 0x245948

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    int     width;
    int     height;
}	t_img;

typedef struct s_size
{
    int     width;
    int     height;
}   t_size;

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_img	img;
    t_img   bone;
    t_img   background;
    t_img   wall;
    t_img   player;
    t_img   exit;
    t_size  pos;
    char    **tab;
    char    *type;
    int     acquired;
    int     objective; 
}	t_data;

typedef struct s_count
{
    int     P;
    int     E;
    int     C;
}   t_count;


char	**ft_split(char const *str, char c);
char	**ft_free(char **str, int k);

char	*get_next_line(int fd);


void so_long(char **tab, t_size size, t_count count);
int	handle_no_event(void *data);
int press_input(int keysym, t_data *data);
void    put_img_to_img(t_img *dest, t_img *src, int x_offset, int y_offset);
void    init_asset(t_data *data, t_img *asset, char *path);
void	render_background(t_img *dest, t_img *src, t_size window);

void    print_error(void);
void    parser(char **tab, t_size size, t_count *count);

// get_next_line_util
char	*ft_strjoin(char *s1, char *s2, int stop);
int		ft_strlen(char *src);
void	ft_bzero(void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
char	**ft_superdup(char **tab, t_size size);

#endif
