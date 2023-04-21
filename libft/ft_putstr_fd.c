/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:17:33 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/22 14:41:41 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("text", O_CREAT | O_RDWR, 777);
	if (fd > 0)
	{
		ft_putstr_fd("abc", fd);
	}
}
*/