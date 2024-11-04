/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:03:27 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/03 20:10:34 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(char const *format, ...);
int ft_putchar(int format);
int ft_putstr(char *format, int *counts);
int ft_putptr(void *, int *counts);
int ft_putnbr(int, int *counts);
int ft_putunsnbr(unsigned int, int *counts);
int ft_puthex(unsigned long, int *counts);

#endif
