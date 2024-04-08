/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:01:13 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/22 16:57:53 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s2)
		return (0);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	if (!str)
		return (NULL);
	while (*str != '\0' && ch != *str)
		str++;
	if (*str == ch)
		return ((char *)str);
	return (0);
}
