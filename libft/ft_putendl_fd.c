/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:31:46 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/22 14:43:57 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("text", O_CREAT | O_RDWR, 777);
	if (fd > 0)
	{
		ft_putendl_fd("abc", fd);
	}
}
*/