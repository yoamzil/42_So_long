/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:23:57 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/21 20:03:33 by yoamzil          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map.array = read_map(argv[1]);
		// if (is_valid_map(&map) && is_valid_arg(argv[1]))
		// {
		// 	init_game(&map);
		// 	start_gameplay(&map);
		// 	mlx_loop(map.mlx);
		// }
		// else
		// {
		// 	if (map.array)
		// 		free_map(map.array);
		// 	printf("Invalid Map");
		// 	exit(1);
		// }
	}
	else
	{
		printf("Invalid Syntax");
		exit(1);
	}
	return (0);
}
