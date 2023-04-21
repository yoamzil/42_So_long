/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:35:55 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/14 02:39:05 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	pointer = (char *)malloc(len + 1);
	if (!pointer)
		return (0);
	ft_memmove(pointer, s + start, len);
	pointer[len] = '\0';
	return (pointer);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "Youness";
	printf("%s", ft_substr(str, 2, 9));
}
*/