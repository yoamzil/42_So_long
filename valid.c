/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:13:27 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/25 21:58:52 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	if (width < 2 || height < 2)
		return (0);
	i = -1;
	while (++i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
	}
	j = 1;
	while (j < height - 1)
	{
		if (map[j][0] != '1' || map[j][width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	has_valid_pec(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	game->num_collect = 0;
	game->num_player = 0;
	game->num_exit = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->num_player++;
			else if (game->map[i][j] == 'E')
				game->num_exit++;
			else if (game->map[i][j] == 'C')
				game->num_collect++;
			j++;
		}
	}
	if (game->num_player != 1 || game->num_exit != 1 || game->num_collect == 0)
		return (0);
	return (1);
}

int	is_valid_map_chars(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_map(t_game *game)
{
	if (is_rectangular(game->map) && is_surrounded_by_walls(game->map)
		&& has_valid_pec(game) && is_valid_map_chars(game->map))
		return (1);
	return (0);
}
