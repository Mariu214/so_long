/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:40:10 by malaimo           #+#    #+#             */
/*   Updated: 2025/12/03 13:19:45 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int stop)
{
	char	*tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tab = ft_calloc(sizeof(char), (ft_strlen(s1) + stop + 1));
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (j < stop)
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	free(s1);
	return (tab);
}

void	ft_bzero(void *src, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)src;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*tab;
	long int	n2;
	long int	s2;

	n2 = (long int)nmemb;
	s2 = (long int)size;
	if (nmemb * size > SIZE_MAX || (n2 < 0 && s2 < 0))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup == NULL)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_superdup(char **tab, t_size size)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_calloc(sizeof(char *), (size.height + 1));
	while (tab[i])
	{
		temp[i] = ft_strdup(tab[i]);
		i++;
	}
	return (temp);
}
