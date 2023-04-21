/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:28:56 by yoamzil           #+#    #+#             */
/*   Updated: 2023/04/21 19:50:27 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*pointer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pointer = malloc(my_strlen(s1) + my_strlen(s2) + 1);
	if (pointer == 0)
		return (0);
	while (s1 && s1[i])
	{
		pointer[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		pointer[j + i] = s2[j];
		j++;
	}
	pointer[i + j] = '\0';
	free(s1);
	return (pointer);
}

char	*my_strchr(char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (!s[i] || (s[i] == c && s[i + 1] == '\0'))
		return (0);
	str = malloc (my_strlen(s) - i);
	if (!str)
		return (0);
	i += 1;
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
