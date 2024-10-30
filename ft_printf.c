/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:42:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/10/30 16:00:40 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	conver_type(va_list args, char const *format, int *counts)
{

}

int ft_printf(char const *format, ...)
{
	va_list args;
	int	counts;

	counts = 0;
	va_start(args, format);
	while (*format)
	{
        if (*format == '%')
		{
            format++;
            if (conver_type(args, *format, &counts) == -1)
                return -1;  // Error en el especificador
        }
        else
		{
            counts += write(1, format, 1);
        }
        format++;
    }
	va_end(args);
	return(counts);
}