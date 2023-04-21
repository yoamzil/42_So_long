/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:24:06 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/21 02:49:57 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
// # include <mlx.h>
typedef struct	s_map
{
    int     width;
    int     height;
    char    **array;
	void	*mlx;
}	t_map;

char	**read_map(char *filepath);

#endif