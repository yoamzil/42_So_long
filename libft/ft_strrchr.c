/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:17 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/05 22:12:46 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char )c)
			return (&str[i]);
		i--;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Youness is the goat";
	printf("%s", ft_strrchr(str, 's'));
	return (0);
}
*/