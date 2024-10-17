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

// Specifiers:
// c - Prints a single character.
// s - Prints a string.
// p - The void * pointer argument has to be printed in hexadecimal format.
// d - Prints a decimal (base 10) number.
// i - Prints an integer in base 10, same as %d.
// u - Prints an unsigned decimal (base 10) number.
// x - Prints a number in hexadecimal (base 16) lowercase format.
// X - Prints a number in hexadecimal (base 16) uppercase format.
// % - Prints a percent sign.
//
// Flags:
// '-' - Left-justify within the given field width; Right justification is the default
// '0' - Left-pads the number with zeroes (0) instead of spaces when padding is specified
// '.' - Precision
// '#' -
// ' ' -
// ''

int ft_printf(const char *str, ...) {
    int i;
    va_list args;

    va_start(args, str);
    i = 0;
    while (str[i]) {
        if (str[i] != '%')
            ft_putchar_fd(str[i], 0);
        else {
            i++;
            //check_flags()
            //check_specifiers()
        }
        i++;
    }
}
