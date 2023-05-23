/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/23 23:17:07 by yoamzil          ###   ########.fr       */
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

int	has_double_newline(char *map)
{
    while (*map)
    {
        if (*map == '\n' && *(map + 1) == '\n')
		{
			printf("Error... Invalid Map\n");
			exit(1);
		}
        map++;
    }
    return 0;
}
int	is_rectangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
        // printf("dkhel l while\n");
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	int i;
	int j;
	int width;
	int height;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	if (width < 2 || height < 2)
		return (0);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
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


int has_valid_pec(t_game *game)
{
    int i = 0;
    int j = 0;

    game->num_collect = 0;
    game->num_player = 0;
    game->num_exit = 0;

    while (game->map[i])
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
        i++;
    }
    if (game->num_player != 1 || game->num_exit == 0 || game->num_collect == 0)
        return (0);
    // printf("lmushkil mashy f valid_pec\n");
    return (1);
}

int is_valid_map_chars(char **map)
{
    int i = 0;
    int j;
    while (map[i])
	{
        j = 0;
        while (map[i][j]) {
            char c = map[i][j];
            if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1') {
                return 0;
            }
            j++;
        }
        i++;
    }
    // printf("lmushkil mashy f valid_map_char\n");
    return 1;
}

int is_valid_map(t_game *game)
{
    // printf("dkhel l valid map\n");
    // exit(0);
    if (is_rectangular(game->map) && is_surrounded_by_walls(game->map) && has_valid_pec(game) && is_valid_map_chars(game->map))
        return (1);
    return (0);
}

int	is_valid_arg(char *arg)
{
	int	len;

	if (!arg)
		return (0);

	len = 0;
	while (arg[len] != '\0')
		len++;
	if (arg[len - 1] == 'r' && arg[len - 2] == 'e' && arg[len - 3] == 'b' && arg[len - 4] == '.')
	{
		return (1);
	}
	return (0);
}
static void	size_window_init(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(game->map[0]) * 64;
	while (game->map[i] != NULL)
		i++;
	game->map_height = i * 64;
}

static void	initialize_image(t_game *game)
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

void	img_drawing(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->window, image, x * 64, y * 64);
}

static void	player_drawing(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_drawing(game, image, x, y);
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
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (is_valid_map(&game) && is_valid_arg(argv[1]))
		{
			printf("Valid Map");
			initialize_game(&game);
		// 	start_gameplay(&map);
		// 	mlx_loop(map.mlx);
		}
		else
		{
			if (game.map)
				// free_map(game.array);
				printf("Error... Invalid Map\n");
			exit(1);
		}
	}
	else
	{
		printf("Invalid Syntax\n");
		exit(1);
	}
	return (0);
}
