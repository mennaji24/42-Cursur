/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:27:25 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/05 12:27:29 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define TYPES "cspdiuxX"

int		ft_puthex_num(char c, unsigned int n, int *count);
int		ft_puthex_nummax(char c, unsigned int n, int *count);
int		ft_put_pointer(char c, unsigned long long n, int *count);
int		ft_putuns(unsigned int n);
int		ft_putint(int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *str);
int		ft_char_convert(va_list args, char c);
int		ft_printf(const char *format, ...);

#endif
