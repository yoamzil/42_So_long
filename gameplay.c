/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:11:07 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/25 22:29:46 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	button_click(int key, t_game *game)
{
	if (key == 53)
		exit_game(game);
	else if (!game->endgame)
	{
		events(key, game);
		if (game->endgame == 1)
		{
			exit_game(game);
		}
	}
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->space_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->collect_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	game->mlx = NULL;
	exit(0);
}

void	events(int key, t_game *game)
{
	if (key == 13)
	{
		game->y_player -= 1;
		player_up(game);
	}
	else if (key == 1)
	{
		game->y_player += 1;
		player_down(game);
	}
	else if (key == 2)
	{
		game->x_player += 1;
		player_right(game);
	}
	else if (key == 0)
	{
		game->x_player -= 1;
		player_left(game);
	}
}

void	start_gameplay(t_game *game)
{
	mlx_hook(game->window, 2, 0, button_click, game);
	mlx_hook(game->window, 17, 0, exit_game, game);
}
