/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:48:28 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/27 15:08:41 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

/*
#include<stdio.h>

int main (){
	printf("%d", ft_putstr("a string : hello"));
	printf("\n");
	printf("   %d", printf("a string : %s", "hello"));
}
*/