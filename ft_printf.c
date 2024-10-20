/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteteria <hteteria@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:49:50 by hteteria          #+#    #+#             */
/*   Updated: 2024/10/16 23:49:50 by hteteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_hex_uns(unsigned long n, char x, int hex, int chars) {
    if (hex) {
        char    *base;

        if (x == 'x')
            base = "0123456789ABCDEF";
        else
            base = "0123456789abcdef";
        if (n > 15)
            put_hex_uns(n / 16, x, hex, chars);
        ft_putchar_fd(base[n % 16], 0);
        chars++;
    } else {
        if (n >= 10)
		    put_hex_uns(n / 10, x, hex, chars);
	    ft_putchar_fd(n % 10 + '0', 0);
        chars++;
    }
}

static void count_chars(int chars, va_list args, const char *str, int i) {
    if (str[i] == 'c' || str[i] == '%') {
        chars++;
        va_arg(args, int);
    } else if (str[i] == 's')
        chars += ft_strlen(va_arg(args, char *));
    else if (str[i] == 'd' || str[i] == 'i')
        chars += ft_strlen(ft_itoa(va_arg(args, int)));
    else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
        va_arg(args, unsigned int);
    else if (str[i] == 'p')
        va_arg(args, void *);
}

// static void check_flags() {}

static void check_specifiers(const char *str, int i, va_list args, int chars) {
    if (str[i] == 'c')
        ft_putchar_fd(va_arg(args, int), 0);
    else if (str[i] == 's')
        ft_putstr_fd(va_arg(args, char *), 0);
    else if (str[i] == 'p') {
        unsigned long addr = (unsigned long)va_arg(args, void *);
        ft_putstr_fd("0x", 0);
        chars += 2;
        put_hex_uns(addr, 0, 1, chars);
    } else if (str[i] == 'd' || str[i] == 'i')
        ft_putnbr_fd(va_arg(args, int), 0);
    else if (str[i] == 'u')
        put_hex_uns(va_arg(args, unsigned int), 0, 0, chars);
    else if (str[i] == 'x' || str[i] == 'X')
        put_hex_uns(va_arg(args, unsigned int), str[i], 1, chars);
    else if (str[i] == '%')
        ft_putchar_fd('%', 0);
}

int ft_printf(const char *str, ...) {
    int     i;
    int     chars;
    va_list args;
    va_list args_cp;

    va_start(args, str);
    va_copy(args_cp, args);
    i = 0;
    chars = 0;
    while (str[i]) {
        if (str[i] != '%') {
            ft_putchar_fd(str[i], 0);
            chars++;
        } else {
            i++;
            chars++;
            //check_flags()
            check_specifiers(str, i, args, chars);
            count_chars(chars, args_cp, str, i);
        }
        i++;
    }
    ft_putchar_fd('\n', 0);
    va_end(args);
    return(chars);
}
