/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:16:59 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/10 16:57:07 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

int main(void)
{
    int ret;

    // Test for characters
    ret = ft_printf("Test with char: %c\n", 'A');
    printf("ft_printf returned: %d\n", ret);

    // Test for strings
    ret = ft_printf("Test with string: %s\n", "Hello World!");
    printf("ft_printf returned: %d\n", ret);

    // Test for pointers (with NULL)
    ret = ft_printf("Test with NULL pointer: %p\n", NULL);
    printf("ft_printf returned: %d\n", ret);

    // Test for pointers with a non-null address
    int x = 42;
    ret = ft_printf("Test with pointer to address: %p\n", &x);
    printf("ft_printf returned: %d\n", ret);

    // Test for integers (with negative and positive numbers)
    ret = ft_printf("Test with integer (negative): %d\n", -1234);
    printf("ft_printf returned: %d\n", ret);

    ret = ft_printf("Test with integer (positive): %d\n", 5678);
    printf("ft_printf returned: %d\n", ret);

    // Test for unsigned integers
    ret = ft_printf("Test with unsigned int: %u\n", 123456);
    printf("ft_printf returned: %d\n", ret);

    // Test for hexadecimal (lowercase)
    ret = ft_printf("Test with hexadecimal (lowercase): %x\n", 255);
    printf("ft_printf returned: %d\n", ret);

    // Test for hexadecimal (uppercase)
    ret = ft_printf("Test with hexadecimal (uppercase): %X\n", 255);
    printf("ft_printf returned: %d\n", ret);

    // Test for percentage symbol
    ret = ft_printf("Test with percentage: %%\n");
    printf("ft_printf returned: %d\n", ret);

    // Test for a NULL value in string
    ret = ft_printf("Test with NULL string: %s\n", NULL);
    printf("ft_printf returned: %d\n", ret);

    // Test with a mixed case
    char c = 'A';
    char *str = "Hello World!";
    int num = 1234;
    void *ptr = (void *)0x16d9436f4;

    int result = ft_printf("Test with mixed case: %c, %s, %d, %p\n", c, str, num, ptr);
    printf("ft_printf returned: %d\n", result);

    return 0;
}
