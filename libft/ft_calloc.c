/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:09:52 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/21 20:13:23 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	num;

	num = count * size;
	pointer = (char *)malloc(num);
	if (pointer == 0)
		return (0);
	ft_bzero(pointer, num);
	return (pointer);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str = ft_calloc(4, 4);
	int	i = 0;
	while (i < 4)
	{
		printf("%d\n", str[i]);
		i++;
	}
}
*/