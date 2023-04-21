/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:59:05 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/21 12:41:16 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lens;
	size_t	lend;

	i = 0;
	j = 0;
	lens = ft_strlen(src);
	if (dstsize == 0)
		return (lens);
	lend = ft_strlen(dst);
	if (lend >= dstsize)
		return (lens + dstsize);
	while (dst[j] != '\0')
		j++;
	while (src[i] != '\0' && (j + 1) < dstsize)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (lens + lend);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "Youness";
	char	dst[] = "Amzil";
	printf("%zu", ft_strlcat(dst, src, 2));
	printf("%zu", strlcat(dst, src, 2));
}
*/