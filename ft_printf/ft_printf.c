/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:10:43 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/27 15:07:19 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chara(va_list agp, char i)
{
	int	count;

	count = 0;
	if (i == '%')
		count += ft_putchar('%');
	else if (i == 'c')
		count += ft_putchar(va_arg(agp, int));
	else if (i == 's')
		count += ft_putstr(va_arg(agp, char *));
	else if (i == 'd' || i == 'i')
		count += ft_putnbr(va_arg(agp, int));
	else if (i == 'u')
		count += ft_putnbr_uns(va_arg(agp, unsigned int));
	else if (i == 'p')
	{
		count += ft_putstr("0x");
		count += ft_convert(va_arg(agp, unsigned long));
	}
	else if (i == 'x')
		count += ft_hexa(va_arg(agp, unsigned int), "0123456789abcdef");
	else if (i == 'X')
		count += ft_hexa(va_arg(agp, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	agp;
	int		i;
	int		count;

	va_start(agp, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_chara(agp, s[i]);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(agp);
	return (count);
}
