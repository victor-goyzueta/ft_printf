/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:03:27 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/06 17:53:00 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(char const *format, ...);
int	ft_putchar(int ch, int *counts);
int	ft_putstr(char *str, int *counts);
int	ft_putptr(void *ptr, int *counts);
int	ft_putnbr(int nbr, int *counts);
int	ft_putunsnbr(unsigned int unsnbr, int *counts);
int	ft_puthex(unsigned long num, int *counts, char format);

#endif
