#include "so_long.h"

void    print_error()
{
    write(2, "Error\n", 6);
    exit(1);
}


char	**filling_loop(char **tab, int x, int y, t_count *count)
{
	if (tab[y][x] == 'E')
		count->E++;
	if (tab[y][x] == 'C')
		count->C++;
	tab[y][x] = '1';
	if (tab[y - 1][x] != '1')
		tab = filling_loop(tab, x, y - 1, count);
	if (tab[y][x - 1] != '1')
		tab = filling_loop(tab, x - 1, y, count);
	if (tab[y + 1][x] != '1')
		tab = filling_loop(tab, x, y + 1, count);
	if (tab[y][x + 1] != '1')
		tab = filling_loop(tab, x + 1, y, count);
	return (tab);
}

int	flood_filling(char **tab, t_data *data, t_size index)
{
	int		y;
	int		x;
	t_count	verif;

	y = 1;
	verif.E = 0;
	verif.C = 0;
	while (index.height == 0)
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
			{
				index.width = x;
				index.height = y;
			}
			x++;
		}
		y++;
	}
	filling_loop(tab, index.width, index.height, &verif);
	if (data->count.E != verif.E || data->count.C != verif.C)
		return(1);
	return(0);
}

int	pars_middle(char *tab, t_data *data)
{
    int i;

    i = 1;
	if (tab[0] != '1')
        return(1);
	while (tab[i])
	{
		if (tab[i] != 'P' && tab[i] != 'E' && tab[i] != 'C' 
			&& tab[i] != '0' && tab[i] != '1' && tab[i] != 'D')
			return(1);
		if (tab[i] == 'P')
			data->count.P++;
		if (tab[i] == 'E')
			data->count.E++;
		if (tab[i] == 'C')
			data->count.C++;
		if (tab[i++] == 'D')
			data->count.D++;
	}
	if (tab[i - 1] != '1')
        return(1);
	return (0);
}

int    parser(t_data *data)
{
    int y;
	int		i;
	t_size	index;
	char	**temp;

    i = 0;
	temp = ft_superdup(data->tab, data->size);
	index.height = 0;
    y = 1;
	while (data->tab[0][i] && data->tab[data->size.height - 1][i])
		if (data->tab[0][i] != '1' || data->tab[data->size.height - 1][i++] != '1')
            return(ft_free(temp, data->size.height), 1);
	while (y < data->size.height - 1)
        if (pars_middle(data->tab[y++], data))
			return (ft_free(temp, data->size.height), 1);
	if (data->count.P != 1 || data->count.E != 1 || data->count.C < 1)
    	return(ft_free(temp, data->size.height), 1);
	if (flood_filling(temp, data, index))
		return (ft_free(temp, data->size.height), 1);
	return (ft_free(temp, data->size.height), 0);
}
