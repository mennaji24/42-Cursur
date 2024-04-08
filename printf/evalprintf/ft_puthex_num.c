/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:12 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/13 15:35:34 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_num(char c, unsigned int n, int *count)
{
	char	*base;

	if (n >= 16)
		ft_puthex_num(c, n / 16, count);
		base = "0123456789abcdef";
	ft_putchar(base[n % 16]);
	*count = *count + 1;
	return (0);
}

int	ft_puthex_nummax(char c, unsigned int n, int *count)
{
	char	*base;

	if (n >= 16)
		ft_puthex_nummax(c, n / 16, count);
		base = "0123456789ABCDEF";
	ft_putchar(base[n % 16]);
	*count = *count + 1;
	return (0);
}

int	ft_putp_num(char c, unsigned long long n, int *count)
{
	char	*base;

	if (n >= 16)
		ft_putp_num(c, n / 16, count);
		base = "0123456789abcdef";
	ft_putchar(base[n % 16]);
	*count = *count + 1;
	return (0);
}

int	ft_put_pointer(char c, unsigned long long n, int *count)
{
	write(1, "0x", 2);
	*count = *count + 2;
	ft_putp_num(c, n, count);
	return (0);
}
