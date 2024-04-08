/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:26:00 by mennaji           #+#    #+#             */
/*   Updated: 2023/07/07 20:34:03 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char arg)
{
	return (arg >= '0' && arg <= '9');
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (8192);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	i += (nptr[i] == '+' || nptr[i] == '-');
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	char			*ptr;
	unsigned int	i;
	unsigned int	slen;

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

int	count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s != c && *s)
				++s;
		}
		else
			++s;
	}
	return (count);
}
