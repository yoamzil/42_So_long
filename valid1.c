/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:34:00 by yoamzil           #+#    #+#             */
/*   Updated: 2023/05/25 17:55:49 by yoamzil          ###   ########.fr       */
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

int	has_double_newline(char *map)
{
	while (*map)
	{
		if (*map == '\n' && *(map + 1) == '\n')
		{
			ft_printf("Error\nInvalid Map\n");
			exit(1);
		}
		map++;
	}
	return (0);
}
