/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:16:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/09 03:41:25 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int result1 = 0;

    result1 = ft_printf("%x", INT64_MAX);
    printf("\n");
    ft_printf("%i", result1);

    int result2 = 0;
    printf("\n");
    //result2 = printf("%x", INT64_MAX);
    result2 = printf("%llx", INT64_MAX);
    printf("\n%i", result2);
    return 0;
}