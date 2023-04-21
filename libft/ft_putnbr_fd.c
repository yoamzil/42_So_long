/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:52:33 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/22 14:48:21 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * (-1), fd);
	}
	else if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(2, fd);
		ft_putnbr_fd(147483648, fd);
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
		ft_putnbr_fd(123, fd);
	}
}
*/