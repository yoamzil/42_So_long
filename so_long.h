/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:24:06 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/22 14:48:41 by yoamzil          ###   ########.fr       */
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

typedef struct s_game
{
	char	**map;
	int		num_player;
	int		num_collect;
	int		num_exit;
	// void	*mlx;
	// void	*win;
	// void	*img_backg;
	// void	*img_wall;
	// void	*img_player;
	// void	*img_collect;
	// void	*img_exit;
	// void	*img_losing;
	// int		map_w;
	// int		map_h;
	// int		img_w;
	// int		img_h;
	// char	*intra_str;
	// int		x_player;
	// int		y_player;
	// int		moves;
	// int		endgame;
}	t_game;

char	**read_map(char *filepath);
int     is_valid_map(t_game *map);
int     is_rectangular(char **map);
int     is_valid_arg(char *arg);
int     is_surrounded_by_walls(char **map);

#endif