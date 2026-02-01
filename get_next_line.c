/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:26:18 by malaimo           #+#    #+#             */
/*   Updated: 2025/12/03 13:20:44 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static char	*copy(char *dest)
// {
// 	int		i;
// 	char	*tab;

// 	i = 0;
// 	while (dest[i] != '\0')
// 		i++;
// 	tab = ft_calloc(sizeof(char), (i));
// 	i = 0;
// 	while (dest[i] != '\0')
// 	{
// 		tab[i] = dest[i];
// 		i++;
// 	}
// 	tab[i] = '\0';
// 	return (tab);
// }

// int	verification(char *dest)
// {
// 	int	i;

// 	i = 0;
// 	if (!dest)
// 		return (1);
// 	while (dest[i])
// 	{
// 		if (dest[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

char	*ft_nullify(char *array)
{
	char	*tab;

	free(array);
	tab = NULL;
	return (tab);
}

static char	*ft_remplissage(char *array, int fd)
{
	char	*temp;
	int		stop;

	temp = ft_calloc(sizeof(char), (1));
	stop = 1;
	while (stop == 1)
	{
		stop = read(fd, temp, 1);
		if (stop < 0)
		{
			free(temp);
			free(array);
			return (NULL);
		}
		if (stop > 0)
		{
			array = ft_strjoin(array, temp, stop);
		}
	}
	free(temp);
	return (array);
}

char	*get_next_line(int fd)
{
	static char	*array;
	int			i;

	i = 0;
	if (fd < 0)
		return (NULL);
	if (!array)
		array = ft_calloc(sizeof(char), (1));
	array = ft_remplissage(array, fd);
	if (!array)
		return (NULL);
	if (!array[0])
	{
		array = ft_nullify(array);
		free(array);
		return (NULL);
	}
	while (array[i + 1])
		i++;
	while (array[i] == '\n')
	{
		array[i] = '\0';
		i--;	
	}
	return (array);
}
