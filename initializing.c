/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:02:51 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/25 22:07:16 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_window_init(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(game->map[0]) * 32;
	while (game->map[i] != NULL)
		i++;
	game->map_height = i * 32;
}

void	initialize_image(t_game *game)
{
	game->collect_img = mlx_xpm_file_to_image
		(game->mlx, "imgs/collect.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image
		(game->mlx, "imgs/exit.xpm", &game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image
		(game->mlx, "imgs/player.xpm", &game->img_width, &game->img_height);
	game->space_img = mlx_xpm_file_to_image
		(game->mlx, "imgs/space.xpm", &game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image
		(game->mlx, "imgs/wall.xpm", &game->img_width, &game->img_height);
}

int	map_drawing(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img_drawing(game, game->space_img, x, y);
			if (game->map[y][x] == '1')
				img_drawing(game, game->wall_img, x, y);
			else if (game->map[y][x] == '0')
				img_drawing(game, game->space_img, x, y);
			else if (game->map[y][x] == 'C')
				img_drawing(game, game->collect_img, x, y);
			else if (game->map[y][x] == 'E')
				img_drawing(game, game->exit_img, x, y);
			else if (game->map[y][x] == 'P')
				player_drawing(game, game->player_img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	img_drawing(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->window, image, x * 32, y * 32);
}

void	player_drawing(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_drawing(game, image, x, y);
}

