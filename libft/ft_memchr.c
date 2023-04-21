/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:46:15 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/03 19:09:54 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		if (str[i] == (char )c)
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Youness is the goat";
	printf("%s", ft_strchr(str, 'i'));
	return (0);
}
*/