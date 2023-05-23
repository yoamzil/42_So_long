/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:23 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/23 23:14:05 by yoamzil          ###   ########.fr       */
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
	void	*mlx;
	void	*window;
	void	*space_img;
	void	*wall_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	// void	*img_losing;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	// char	*intra_str;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
}	t_game;

char	**read_map(char *filepath);
int     is_valid_map(t_game *map);
int     is_rectangular(char **map);
int     is_valid_arg(char *arg);
int     is_surrounded_by_walls(char **map);
int		has_double_newline(char *map);

#endif