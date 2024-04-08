/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:34:40 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/13 15:35:18 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 214748364)
	{
		write(1, "214748364", 9);
		return (9);
	}
	if (n >= 10)
		count += ft_putuns(n / 10);
		n = n % 10;
	ft_putchar(n % 10 + '0');
	return (count + 1);
}

int	ft_putint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putint(n / 10);
		n = n % 10;
	ft_putchar(n % 10 + 48);
	return (count + 1);
}
