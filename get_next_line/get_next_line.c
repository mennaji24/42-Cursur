/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:11:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/22 16:48:30 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *box)
{
	char	*buffer;
	int		n;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	n = 1;
	while (n > 0 && (ft_strchr(box, '\n') == 0))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[n] = '\0';
		box = ft_strjoin(box, buffer);
	}
	free(buffer);
	return (box);
}

char	*ft_get_line(char *buckup)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!buckup[i])
		return (0);
	while (buckup[i] != '\0' && buckup[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (0);
	i = 0;
	while (buckup[i] && buckup[i] != '\n')
	{
		new_line[i] = buckup[i];
		i++;
	}
	if (buckup[i] == '\n')
	{
		new_line[i] = '\n';
		i++;
	}
	new_line[i] = 0;
	return (new_line);
}

char	*ft_clean(char *str)
{
	char	*ptr;
	int		i;
	int		c;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!ptr)
		return (NULL);
	c = 0;
	i += 1;
	while (str[i])
		ptr[c++] = str[i++];
	ptr[c] = '\0';
	free(str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_clean(buffer);
	return (line);
}
