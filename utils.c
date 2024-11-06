/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:37:27 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/06 14:59:03 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nbr, int *counts)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (counts += 11);
	}
	else if (nbr < 0)
	{
		counts += ft_putchar('-', counts);
		ft_putnbr(-nbr, counts);
	}
	else if (nbr > 9)
	{
		ft_putnbr((nbr / 10), counts);
		counts += ft_putchar((nbr % 10) + '0', counts);
	}
	else
		counts += ft_putchar(nbr + '0', counts);
	return (*counts);
}

int	ft_unsnbr(unsigned int unsnbr, int *counts)
{
	if (unsnbr > 9)
	{
		ft_putunsnbr((unsnbr / 10), counts);
		counts += ft_putchar((unsnbr % 10) + '0', counts);
	}
	else
		counts += ft_putchar(unsnbr + '0', counts);
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

int	ft_putptr(void *ptr, int *counts)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (counts += 5);
	}
	counts += ft_putstr("0x", counts);
	counts += ft_puthex(p, counts, 'x');
	return (*counts);
}
