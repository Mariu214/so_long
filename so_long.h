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

typedef struct s_count
{
    int     P;
    int     E;
    int     C;
    int     D;
}   t_count;

typedef struct s_dog
{
    t_size  position;
}   t_dog;

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
    t_img   dog;
    t_size  pos;
    t_dog   *dogs;
    char    **tab;
    t_size  size;
    t_size  position_exit;
    int     acquired;
    t_count count; 
    int     victory;
}	t_data;

char	**ft_split(char const *str, char c);
char	**ft_free(char **str, int k);

char	*get_next_line(int fd);

int verif_dog_presence(t_data *data, int x, int y, int i);
void    defeat(t_data  *data);
char    *choose_texture_dog(t_data *data);

void so_long(t_data *data);
int	handle_no_event(t_data *data);
int press_input(int keysym, t_data *data);
void    put_img_to_img(t_img *dest, t_img *src, int x_offset, int y_offset);
void    init_asset(t_data *data, t_img *asset, char *path);
void	render_background(t_img *dest, t_img *src, t_data *data);
int    stopgame(t_data *data);

void    print_error(void);
int    parser(t_data *data);

void    victory(t_data  *data);
void    dogs_moves(t_data *data);

// get_next_line_util
char	*ft_strjoin(char *s1, char *s2, int stop);
int		ft_strlen(char *src);
void	ft_bzero(void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
char	**ft_superdup(char **tab, t_size size);

#endif
