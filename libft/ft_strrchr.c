/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:13 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/08 17:56:16 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*char_find;

	char_find = 0;
	while (*str)
	{
		if (*str == (char)ch)
			char_find = (char *)str;
		str++;
	}
	if (ch == 0)
		return ((char *)str);
	return (char_find);
}
