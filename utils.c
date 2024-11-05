/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:37:27 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/05 18:00:03 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putnbr(int format, int *counts)
{
	if (format == -2147483648)
	{
		return (write(1, "-2147483648", 11));
		counts += ft_putchar('-');
		counts += ft_putchar('2');
		ft_putnbr(147483648, counts);
	}
	else if (format < 0)
	{
		ft_putchar('-');
		ft_putnbr(-format, counts);
	}
	else if (format > 9)
	{
		ft_putnbr((format / 10), counts);
		ft_putchar((format % 10) + '0');
	}
	else
		ft_putchar(format + '0');
    return (*counts);
}

int	ft_unsnbr(unsigned int format, int *counts)
{
	if (format > 9)
	{
		ft_putnbr((format / 10), counts);
		ft_putchar((format % 10) + '0');
	}
	else
		ft_putchar(format + '0');
    return (*counts);
}

int	ft_puthex(unsigned long num, int *counts, char format)
{
	if (format == 'x')
		format = 'a';
	else
		format = 'A';
		
	if (num < 16)
	{
		if (num >= 0 && num <= 9)
		{
			num += '0';
		}
		else if (num >= 10 && num <= 15)
		{
			num += format;
		}
	}
	else
	{
		ft_puthex((num / 16), counts, format);
		ft_putchar((num % 16) + '0');
	}
    return (*counts);
}