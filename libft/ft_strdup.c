/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:06:08 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/21 20:18:16 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*target;
	size_t	len;

	len = ft_strlen(s1);
	target = malloc((len + 1) * sizeof(char));
	if (target == 0)
		return (0);
	ft_memmove(target, s1, len + 1);
	return (target);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "Youness";

	printf("%s", ft_strdup(s1));
}
*/