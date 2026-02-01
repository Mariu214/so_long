#include "so_long.h"

t_size	get_size(char **src)
{
	int		i;
	t_size	size;

	i = 0;
	size.width = ft_strlen(src[i]);
	size.height = 0;
	while (src[i])
	{
		if (size.width != ft_strlen(src[i++]))
			print_error();
		size.height++;
	}
	if (size.height < 3)
		print_error();
	return (size);
}

int	main(int ag, char **av)
{
	int 	fd;
	char	**tab;
	t_size	size;
	t_count	count;

	(void)ag;
	fd = open(av[1], O_RDWR);
	tab = ft_split(get_next_line(fd), '\n');
	size = get_size(tab);
	parser(tab, size, &count);
	so_long(tab, size, count);
	return(0);
}
