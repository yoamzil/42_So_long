/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/26 20:00:42 by yoamzil          ###   ########.fr       */
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
	map_array = ft_split(accumulator, '\n');
	free(accumulator);
	close(fd);
	return (map_array);
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (is_valid_map(&game) && is_valid_arg(argv[1]))
		{
			printf("Valid Map");
		// 	init_game(&map);
		// 	start_gameplay(&map);
		// 	mlx_loop(map.mlx);
		}
		else
		{
			if (game.map)
				// free_map(game.array);
				printf("Invalid Map\n");
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
