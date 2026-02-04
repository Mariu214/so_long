#include "so_long.h"

void    print_error()
{
    write(2, "Error\n", 6);
    exit(1);
}

t_size	get_size(char **src)
{
	int		i;
	t_size	size;
	int		verif;

	i = 0;
	verif = 0;
	size.width = ft_strlen(src[i]);
	size.height = 0;
	while (src[i])
	{
		if (size.width != ft_strlen(src[i++]))
			verif = 1;
		size.height++;
	}
	if (size.height < 3)
		verif = 1;
	if (verif == 1)
	{
		ft_free(src, size.height);
		print_error();
	}
	return (size);
}

int	main(int ag, char **av)
{
	int 	fd;
	char	*temp;
	t_data	data;

	(void)ag;
	data.victory = 0;
	data.count.P = 0;
	data.count.E = 0;
	data.count.C = 0;
	data.count.D = 0;
	fd = open(av[1], O_RDWR);
	temp = get_next_line(fd);
	data.tab = ft_split(temp, '\n');
	free(temp);
	data.size = get_size(data.tab);
	if (parser(&data))
	{
		ft_free(data.tab, data.size.height);
		print_error();
	}
	// so_long(&data);
	// ft_free(data.tab, data.size.height);
	return(0);
}
