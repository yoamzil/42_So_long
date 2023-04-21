/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:32:26 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/21 18:38:40 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack1;
	int		needlelen;

	i = 0;
	j = 0;
	haystack1 = (char *)haystack;
	if (!*needle)
		return (haystack1);
	if (len == 0)
		return (0);
	needlelen = ft_strlen(needle);
	while (haystack1[j] != '\0' && needle[i] != '\0' && j < len)
	{
		if (!ft_strncmp(haystack1 + j, needle, needlelen)
			&& j + needlelen <= len)
			return (&haystack1[j]);
		j++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "steph is the goat";
	char	s2[] = "is";
	printf("%s", ft_strnstr(s1, s2, 8));
}
*/