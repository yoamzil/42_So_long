/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:13:33 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/22 13:11:51 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("text", O_CREAT | O_RDWR, 777);
	if (fd > 0)
	{
		ft_putchar_fd('a', fd);
	}
}
*/