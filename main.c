/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:16:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/06 20:06:28 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void)
{
    ft_printf("Hello, world!\n");
    printf("Hello, world!\n");

    ft_printf("%%\n");
    printf("%%\n");

    ft_printf("%y\n");
    printf("%y\n");

    char c = 'a';
    ft_printf("%c\n", c);
    printf("%c\n", c);

    char *s = "Hello again!";
    ft_printf("%s\n", s);
    printf("%s\n", s);

    int n1 = 42;
    int n2 = -2147483648;
    int n3 = -42;
    ft_printf("%d%i%d\n", n1, n2, n3);
    printf("%d%i%d\n", n1, n2, n3);

    unsigned int num = 42;
    ft_printf("%x\n%X\n", num, num);
    printf("%x\n%X\n", num, num);

    ft_printf("%p\n", s);
    printf("%p\n", s);

    ft_printf("%c%d%i%s%x%X%p%%%%HOLA", c, n1, n3, s, num, num, s);
    printf("\n%c%d%i%s%x%X%p%%%%HOLA", c, n1, n3, s, num, num, s);
    return 0;
}