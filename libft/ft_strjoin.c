/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:23:34 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/21 20:26:43 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	int		len;
	int		i;
	int		j;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	pointer = malloc(len + 1);
	if (pointer == 0)
		return (0);
	while (s1[i])
	{
		pointer[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		pointer[j + i] = s2[j];
		j++;
	}
	pointer[i + j] = '\0';
	return (pointer);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "Youness";
	char	s2[] = "Amzil";
	printf("%s", ft_strjoin(s1, s2));
}
*/