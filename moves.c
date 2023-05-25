/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:23:57 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/25 22:35:18 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up(t_game *game)
{
	char	current_tile;

	current_tile = game->map[game->y_player][game->x_player];
	if (current_tile == 'E' && game->num_collect == 0)
	{
		mlx_clear_window(game->mlx, game->window);
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
	}
	else if (current_tile == '1' || current_tile == 'E')
	{
		game->y_player += 1;
	}
	else
	{
		mlx_clear_window(game->mlx, game->window);
		if (current_tile == 'C')
			game->num_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	map_drawing(game);
}

void	player_down(t_game *game)
{
	char	current_tile;

	current_tile = game->map[game->y_player][game->x_player];
	if (current_tile == 'E' && game->num_collect == 0)
	{
		mlx_clear_window(game->mlx, game->window);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
	}
	else if (current_tile == '1' || current_tile == 'E')
	{
		game->y_player -= 1;
	}
	else
	{
		mlx_clear_window(game->mlx, game->window);
		if (current_tile == 'C')
			game->num_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	map_drawing(game);
}

void	player_right(t_game *game)
{
	char	current_tile;

	current_tile = game->map[game->y_player][game->x_player];
	if (current_tile == 'E' && game->num_collect == 0)
	{
		mlx_clear_window(game->mlx, game->window);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
	}
	else if (current_tile == '1' || current_tile == 'E')
	{
		game->x_player -= 1;
	}
	else
	{
		mlx_clear_window(game->mlx, game->window);
		if (current_tile == 'C')
			game->num_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	map_drawing(game);
}

void	player_left(t_game *game)
{
	char	current_tile;

	current_tile = game->map[game->y_player][game->x_player];
	if (current_tile == 'E' && game->num_collect == 0)
	{
		mlx_clear_window(game->mlx, game->window);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
	}
	else if (current_tile == '1' || current_tile == 'E')
	{
		game->x_player += 1;
	}
	else
	{
		mlx_clear_window(game->mlx, game->window);
		if (current_tile == 'C')
			game->num_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	map_drawing(game);
}
