/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:46:52 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/08 17:56:33 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		count;

	count = 0;
	start = 0;
	end = ft_strlen((char *)s1);
	if (!s1 && !set)
		return (0);
	while (ft_strchr(set, s1[start]) && end > start)
		start++;
	while (ft_strchr(set, s1[end - 1]) && start < end)
		end--;
	ptr = malloc(end - start + 1);
	if (!ptr)
		return (0);
	while (start < end)
		ptr[count++] = s1[start++];
	ptr[count] = 0;
	return (ptr);
}
