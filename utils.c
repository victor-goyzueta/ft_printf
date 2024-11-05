/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:37:27 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/05 16:22:10 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putnbr(int format, int *counts)
{
	if (format == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
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

int	ft_puthex(unsigned long format, int *counts)
{
	if (format < 16)
	{
		ft_putnbr((format / 16), counts);
		ft_putchar((format % 16) + '0');
	}
	else
		
    return (*counts);
}