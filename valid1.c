/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/27 22:17:53 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_arg(char *arg)
{
	int	len;

	if (!arg)
		return (0);
	len = 0;
	while (arg[len] != '\0')
		len++;
	if (arg[len - 1] == 'r' && arg[len - 2] == 'e'
		&& arg[len - 3] == 'b' && arg[len - 4] == '.')
	{
		return (1);
	}
	return (0);
}

int	first_empty_line(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
	{
		ft_printf("Error\nEmpty Line Found");
		exit(1);
	}
	return (0);
}

int	has_double_newline(char *map)
{
	while (*map)
	{
		if (*map == '\n' && *(map + 1) == '\n')
		{
			ft_printf("Error\nDouble New Line Found\n");
			exit(1);
		}
		map++;
	}
	return (0);
}
