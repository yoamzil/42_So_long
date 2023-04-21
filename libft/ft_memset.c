/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:55:19 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/21 12:54:43 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;
	char	cc;

	i = 0;
	str = b;
	cc = c;
	while (i < len)
	{
		str[i] = cc;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
int	main(void)
{
	//char	b[16] = "TOOLATE";
	int	b[5] = {1,6,8,5,3};
	printf("%s", ft_memset(b, '8', 5));
	return (0);
}
*/