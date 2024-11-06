/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:42:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/06 20:17:33 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(int ch, int *counts)
{
	write(1, &ch, 1);
	return (*counts++);
}

int	ft_putstr(char *str, int *counts)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (*counts += 6);
	}
	while (*str)
	{
		ft_putchar(*str, counts);
		str++;
	}
	return (*counts);
}

static int	conver_type(va_list args, char const *format, int *counts)
{
	if (*format == 'c')
		return (*counts += ft_putchar(va_arg(args, int), counts));
	else if (*format == 's')
		return (*counts += ft_putstr(va_arg(args, char *), counts));
	else if (*format == 'p')
		return (*counts += ft_putptr(va_arg(args, void *), counts));
	else if (*format == 'd' || *format == 'i')
		return (*counts += ft_putnbr(va_arg(args, int), counts));
	else if (*format == 'u')
		return (*counts += ft_putunsnbr(va_arg(args, unsigned int), counts));
	else if (*format == 'x' || *format == 'X')
	{
		counts += ft_puthex(va_arg(args, unsigned long), counts, *format);
		return (*counts);
	}
	else if (*format == '%')
		return (*counts += ft_putchar('%', counts));
	else
		return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		counts;

	counts = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (conver_type(args, format, &counts) == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
			counts += ft_putchar(*format, &counts);
		format++;
	}
	va_end(args);
	return (counts);
}

