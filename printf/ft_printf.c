/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:58:27 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/13 14:32:18 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_convert(va_list args, char c)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_put_pointer(c, va_arg(args, unsigned long long), &count);
	else if (c == 'd' || c == 'i')
		count += ft_putint(va_arg(args, int));
	else if (c == 'u')
		count += ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthex_num(c, va_arg(args, unsigned int), &count);
	else if (c == 'X')
		ft_puthex_nummax(c, va_arg(args, unsigned int), &count);
	else if (c == '%')
	{
		ft_putchar('%');
		count += 1;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_char_convert(args, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
