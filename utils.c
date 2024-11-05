/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:37:27 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/05 20:41:51 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putnbr(int format, int *counts)
{
	if (format == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (format < 0)
	{
		counts += ft_putchar('-', counts);
		ft_putnbr(-format, counts);
	}
	else if (format > 9)
	{
		ft_putnbr((format / 10), counts);
		counts += ft_putchar((format % 10) + '0', counts);
	}
	else
		counts += ft_putchar(format + '0', counts);
    return (*counts);
}

int	ft_unsnbr(unsigned int format, int *counts)
{
	if (format > 9)
	{
		ft_putunsnbr((format / 10), counts);
		counts += ft_putchar((format % 10) + '0', counts);
	}
	else
		counts += ft_putchar(format + '0', counts);
    return (*counts);
}

int	ft_puthex(unsigned long num, int *counts, char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
		
	if (num >= 16)
		ft_puthex(num / 16, counts, format);
	else
		counts += ft_putchar(base[num % 16], counts);
    return (*counts);
}

int	ft_putptr(void *format, int *counts)
{
	unsigned long	ptr;
	
	ptr = (unsigned long)format;	
	if (!format)
	{
		write(1, "(nil)", 5);
		return (counts += 5);
	}
	counts += ft_putstr("0x", counts);
	counts += ft_puthex(ptr, counts, 'x');
	return (*counts);
}
