/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:24:06 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/21 22:23:25 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct	s_game
{
    char    **map;
    int     width;
    int     height;
    char    **array;
	void	*mlx;
    int     num_player;
    int     num_collect;
    int     num_exit;
}	t_game;

char	**read_map(char *filepath);
int     is_valid_map(t_game *map);
int     is_rectangular(char **map);
int     is_valid_arg(char *arg);
int     is_surrounded_by_walls(char **map);

#endif