#include "so_long.h"

void    print_error(void)
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

void	flood_filling(char **tab, t_count *count, t_size index)
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
	if (count->E != verif.E || count->C != verif.C)
		print_error();
}

void	pars_middle(char *tab, t_count *count)
{
    int i;

    i = 1;
	if (tab[0] != '1')
        print_error();
	while (tab[i])
	{
		if (tab[i] != 'P' && tab[i] != 'E' && tab[i] != 'C' 
			&& tab[i] != '0' && tab[i] != '1')
			print_error();
		if (tab[i] == 'P')
			count->P++;
		if (tab[i] == 'E')
			count->E++;
		if (tab[i++] == 'C')
			count->C++;
	}
	if (tab[i - 1] != '1')
        print_error();
}

void    parser(char **tab, t_size size, t_count *count)
{
    int y;
	int		i;
	t_size	index;
	char	**temp;

    i = 0;
	temp = ft_superdup(tab, size);
	count->P = 0;
	count->E = 0;
	count->C = 0;
	index.height = 0;
    y = 1;
	while (tab[0][i] && tab[size.height - 1][i])
		if (tab[0][i] != '1' || tab[size.height - 1][i++] != '1')
            print_error();
	while (y < size.height - 1)
        pars_middle(tab[y++], count);
	if (count->P != 1 || count->E != 1 || count->C < 1)
    	print_error();
	flood_filling(temp, count, index);
	ft_free(temp, size.height - 1);
}
