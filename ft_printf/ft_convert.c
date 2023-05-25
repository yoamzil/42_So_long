/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:36:19 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/27 14:39:07 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(unsigned long i)
{
	char	*s;
	int		count;

	s = "0123456789abcdef";
	count = 0;
	if (i >= 0 && i <= 15)
		count += ft_putchar(s[i]);
	if (i > 15)
	{
		count += ft_convert(i / 16);
		count += ft_convert(i % 16);
	}
	return (count);
}
/*#include <stdio.h>
int	main()
{
	int *c;

	printf("%lu", c);
}
*/