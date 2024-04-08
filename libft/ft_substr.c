/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:26:07 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/08 17:56:42 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	char			*ptr;
	size_t			i;
	size_t			slen;

	i = 0;
	string = (char *)s;
	slen = ft_strlen(string);
	if (start >= slen)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	ptr = (char *)malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len && string[start + i] != '\0')
	{
		ptr[i] = string[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
