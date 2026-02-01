/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:19:45 by malaimo           #+#    #+#             */
/*   Updated: 2025/11/19 11:42:33 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	supercount(char const *str, char c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i] != '\0')
			&& (str[i + 1] == '\0' || str[i + 1] == c))
			j++;
		i++;
	}
	return (j - 1);
}

char	**ft_free(char **str, int k)
{
	while (k--)
	{
		free(str[k]);
	}
	free(str);
	return (NULL);
}

static void	ft_remplis(char *tab, char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		tab[i] = (char)str[i];
		i++;
	}
	tab[i] = '\0';
}

static char	**ft_principale(char const *str, char c, char **tab)
{
	int	j;
	int	k;
	int	i;

	j = 0;
	i = 0;
	k = 0;
	tab[supercount(str, c) + 1] = NULL;
	while (k <= supercount(str, c))
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i + j] != c && str[i + j])
			j++;
		tab[k] = (char *)ft_calloc(sizeof(char), (j + 1));
		if (!tab[k])
			return (ft_free(tab, k));
		ft_remplis(tab[k], &str[i], c);
		i += j;
		j = 0;
		k++;
	}
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		size;

	size = supercount(str, c);
	tab = (char **)ft_calloc(sizeof(char *), (size + 2));
	if (!tab)
		return (NULL);
	if (!str[0])
		return (tab);
	return (ft_principale(str, c, tab));
}
