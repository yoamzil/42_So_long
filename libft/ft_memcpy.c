/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:09:20 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/05 22:10:28 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ddest;
	char	*ssrc;

	i = 0;
	ddest = dst;
	ssrc = (char *) src;
	if (ddest == 0 && ssrc == 0)
		return (0);
	while (i < n)
	{
		ddest[i] = ssrc[i];
		i++;
	}
	return (ddest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	dest[5];
	char	src[] = "Youness";
	printf("%s", ft_memcpy(dest,src,4));
}
*/
