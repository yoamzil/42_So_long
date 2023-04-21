/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:46:48 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/22 11:20:03 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*pointer;

	i = 0;
	if (!s)
		return (0);
	pointer = malloc(ft_strlen(s) + 1);
	if (!pointer)
		return (0);
	while (s[i] != '\0')
	{
		pointer[i] = f(i, s[i]);
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
/*
#include <stdio.h>

char	f(unsigned int i, char c)
{
	c++;
	return (c);
}
int	main(void)
{
	char	s[] = "Youness";
	printf("%s", ft_strmapi(s, f));
}
*/