/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:54:48 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/27 14:39:59 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int i, char *s)
{
	int	count;

	count = 0;
	if (i > 15)
	{
		count += ft_hexa(i / 16, s);
		count += ft_hexa(i % 16, s);
	}
	else
		count += ft_putchar(s[i]);
	return (count);
}
