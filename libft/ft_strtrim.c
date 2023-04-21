/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:00:40 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/22 11:05:02 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strrchr(set, s1[end]))
		end--;
	len = end - start + 1;
	str = ft_substr(s1, start, len);
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "youness is you r senpai";
	char	set[] = "you";
	printf("%s", ft_strtrim(s,set));
}
*/