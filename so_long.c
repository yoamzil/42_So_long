/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/27 16:38:30 by yoamzil          ###   ########.fr       */
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
	game->window = mlx_new_window
		(game->mlx, game->map_width, game->map_height, "so_long");
	game->moves = 0;
	game->endgame = 0;
	initialize_image(game);
	map_drawing(game);
}

void	error_printing(void)
{
	ft_printf("Error\nInvalid Syntax\n");
	exit(1);
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
			valid_path(game);
			start_gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			error_printing();
		}
	}
	else
	{
		error_printing();
	}
	return (0);
}
