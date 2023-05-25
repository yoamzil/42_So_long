/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/25 22:07:25 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *filepath)
{
	int		fd;
	char	*line;
	char	*accumulator;
	char	*temp_holder;
	char	**map_array;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (NULL); 
	accumulator = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_holder = accumulator;
		accumulator = ft_strjoin(temp_holder, line);
		free(line);
		free(temp_holder);
	}
	has_double_newline(accumulator);
	map_array = ft_split(accumulator, '\n');
	free(accumulator);
	close(fd);
	return (map_array);
}

void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->window = mlx_new_window(game->mlx, game->map_width, game->map_height, "so_long");
	game->moves = 0;
	game->endgame = 0;
	initialize_image(game);
	map_drawing(game);
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

void	start_gameplay(t_game *game)
{
	mlx_hook(game->window, 2, 0, button_click, game);
	mlx_hook(game->window, 17, 0, exit_game, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (is_valid_map(&game) && is_valid_arg(argv[1]))
		{
			initialize_game(&game);
			start_gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
				ft_printf("Error\nInvalid Map\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Error\nInvalid Syntax\n");
		exit(1);
	}
	return (0);
}
