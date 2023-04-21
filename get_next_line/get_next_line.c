/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoamzil <yoamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:05:20 by yoamzil           #+#    #+#             */
/*   Updated: 2022/11/23 18:12:20 by yoamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *s)
{
	int		i;
	char	*str;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] != '\0' & s[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_break(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *s, int fd)
{
	char	*buffer;
	int		r;

	r = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (r == 0)
			break ;
		buffer[r] = '\0';
		s = ft_strjoin(s, buffer);
		if (ft_break(buffer) == 1)
			break ;
	}
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*t;
	char		*result;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
	{
		free(line);
		line = 0;
		return (NULL);
	}
	line = join(line, fd);
	if (!line)
		return (NULL);
	result = new_line(line);
	t = line;
	line = ft_strchr(t, '\n');
	free(t);
	return (result);
}
// int	main(void)
// {
// 	int fd;
// 	char	*s;
// 	fd = open("text.txt", O_CREAT | O_RDONLY, 755);

// 	while ((s = get_next_line(fd)))
// 	{
// 		printf("%s", s);
// 	}
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }