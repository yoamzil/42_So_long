/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:49:22 by yoamzil           #+#    #+#             */
/*   Updated: 2022/10/22 16:39:18 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_num(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			j++;
		}
	}
	return (j);
}

static int	letter_num(char const *str, int i, char c)
{
	int	j;

	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			while (str[i] && str[i] != c)
			{
				i++;
				j++;
			}
		}
		return (j);
	}
	return (0);
}

static char	*get_word(char const *s, char **tab, int i, char c)
{
	int	k;
	int	j;

	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[j] = (char *)malloc(letter_num(s, i, c) + 1);
			if (!tab[j])
				return (0);
			while (s[i] && s[i] != c)
			{
				tab[j][k] = s[i];
				i++;
				k++;
			}
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (0);
	tab = (char **)malloc((word_num(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	get_word(s, tab, i, c);
	return (tab);
}
/*#include <stdio.h>
int	main(void)
{
	char	**str;
	int	i;
	
	str = ft_split("youness was here", ' ');
	i = 0;
	while (i < 4)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}*/