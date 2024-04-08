/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:31:50 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/07 12:12:32 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	j;
	char	*str;

	str = (char *)src;
	if (!dst && !size)
	{
		return (size);
	}
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
	{
		return (size + ft_strlen(str));
	}
	j = 0;
	while (str[j] && dest_len < size - 1)
	{
		dst[dest_len] = str[j];
		dest_len++;
		j++;
	}
	dst[dest_len] = 0;
	return (dest_len + ft_strlen(&str[j]));
}
