/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:23:57 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/21 22:34:43 by yoamzil          ###   ########.fr       */
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

int is_rectangular(char **map)
{
    size_t	row = 0;
    size_t	width = 0;

    if (map == NULL)
        return (0);

    while (map[row] != NULL)
    {
        if (width == 0)
            width = ft_strlen(map[row]);
        else if (width != ft_strlen(map[row]))
            return (0);
        row++;
    }

    return (1);
}

int is_surrounded_by_walls(char **map)
{
    int i, j;
    // Check top and bottom walls
    i = 0;
    while (map[i])
    {
        if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
            return (0);
        i++;
    }
    // Check left and right walls
    i = 1;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if ((j == 0 || j == (int)ft_strlen(map[i]) - 1) && map[i][j] != '1')
                return (0);
            j++;
        }
        i++;
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
    return 1;
}

int is_valid_map(t_game *game)
{
    if (is_rectangular(game->map) && is_surrounded_by_walls(game->map)
        && has_valid_pec(game) && is_valid_map_chars(game->map))
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
		game.array = read_map(argv[1]);
		printf("wselt hna\n");
		if (is_valid_map(&game) && is_valid_arg(argv[1]))
		{
			printf("Valid Map");
		// 	init_game(&map);
		// 	start_gameplay(&map);
		// 	mlx_loop(map.mlx);
		}
		else
		{
			if (game.array)
				// free_map(game.array);
				printf("Invalid Map");
			exit(1);
		}
	}
	else
	{
		printf("Invalid Syntax");
		exit(1);
	}
	return (0);
}
