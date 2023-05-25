/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:23 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/25 22:25:15 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	char	**map;
	void	*window;
	int		num_player;
	int		num_collect;
	int		num_exit;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	void	*space_img;
	void	*wall_img;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
}	t_game;

char	**read_map(char *filepath);
int		is_valid_map(t_game *map);
int		is_valid_arg(char *arg);
int		has_double_newline(char *map);
void	size_window_init(t_game *game);
void	initialize_image(t_game *game);
int		map_drawing(t_game *game);
void	img_drawing(t_game *game, void *image, int x, int y);
void	player_drawing(t_game *game, void *image, int x, int y);
void	free_map(char **map);
void	start_gameplay(t_game *game);
int		button_click(int key, t_game *game);
int		exit_game(t_game *game);
void	events(int key, t_game *game);
void	player_up(t_game *game);
void	player_down(t_game *game);
void	player_right(t_game *game);
void	player_left(t_game *game);

#endif