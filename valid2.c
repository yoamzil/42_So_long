/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:58:24 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/27 17:04:13 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	final_check(char **map_copy, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j <= width)
		{
			if (map_copy[i][j] == 'C')
			{
				ft_printf("Error\nInvalid Path\n");
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	replace(char **map_copy, int i, int j, int *replaced)
{
	map_copy[i][j] = 'P';
	*replaced = 1;
}

char	**directions(char **map_copy, int width, int height, int *replaced)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = 0;
		while (j <= width)
		{
			if (map_copy[i][j] == 'P')
			{
				if (i > 0 && (map_copy[i - 1][j] == 'C' || map_copy[i - 1][j] == '0'))
					replace(map_copy, i - 1, j, replaced);
				if (i < height - 1 && (map_copy[i + 1][j] == 'C' || map_copy[i + 1][j] == '0'))
					replace(map_copy, i + 1, j, replaced);
				if (j > 0 && (map_copy[i][j - 1] == 'C' || map_copy[i][j - 1] == '0'))
					replace(map_copy, i, j - 1, replaced);
				if (j < width && (map_copy[i][j + 1] == 'C' || map_copy[i][j + 1] == '0'))
					replace(map_copy, i, j + 1, replaced);
			}
			j++;
		}
	}
	return (map_copy);
}

void	valid_path(t_game game)
{
	int		i;
	int		replaced;
	char	**res;
	char	**map_copy;

	i = 0;
	replaced = 1;
	map_copy = malloc(sizeof(char *) * game.height);
	while (i < game.height)
	{
		map_copy[i] = ft_strdup(game.map[i]);
		i++;
	}
	while (replaced)
	{
		replaced = 0;
		res = directions(map_copy, game.width, game.height, &replaced);
	}
	final_check(res, game.width, game.height);
	i = 0;
	while (i < game.height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
