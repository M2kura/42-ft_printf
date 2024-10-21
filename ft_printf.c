/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteteria <hteteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:49:50 by hteteria          #+#    #+#             */
/*   Updated: 2024/10/21 21:40:27 by hteteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex_uns(unsigned long n, char x, int hex, int *chars)
{
	char	*base;

	if (hex)
	{
		if (x == 'x')
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
		if (n > 15)
			put_hex_uns(n / 16, x, hex, chars);
		ft_putchar_fd(base[n % 16], 1);
	}
	else
	{
		if (n >= 10)
			put_hex_uns(n / 10, x, hex, chars);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	(*chars)++;
}

static void	count_chars(int *chars, va_list args, const char *str, int i)
{
	char	*itoa;

	if (str[i] == 'c' || str[i] == '%')
	{
		(*chars)++;
		va_arg(args, int);
	}
	else if (str[i] == 's')
		(*chars) += ft_strlen(va_arg(args, char *));
	else if (str[i] == 'd' || str[i] == 'i')
	{
		itoa = ft_itoa(va_arg(args, int));
		(*chars) += ft_strlen(itoa);
		free(itoa);
	}
	else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		va_arg(args, unsigned int);
	else if (str[i] == 'p')
		va_arg(args, void *);
	else
		(*chars)++;
}

static int	check_null(va_list args, int *chars, int *i, const char *str)
{
	va_list	args_cp;
	void	*addr;

	va_copy(args_cp, args);
	(*i)++;
	if (str[(*i)] == 'p' || str[(*i)] == 's')
	{
		addr = va_arg(args_cp, void *);
		if (addr == 0 && str[(*i)] == 'p')
		{
			ft_putstr_fd("(nil)", 1);
			(*chars) += 5;
			return (0);
		}
		else if (addr == 0 && str[(*i)] == 's')
		{
			ft_putstr_fd("(null)", 1);
			(*chars) += 6;
			return (0);
		}
	}
	va_end(args_cp);
	return (1);
}

static void	check_specifiers(const char *str, int *i, va_list args, int *chars)
{
	if (check_null(args, chars, i, str))
	{
		if (str[(*i)] == 'c')
			ft_putchar_fd(va_arg(args, int), 1);
		else if (str[(*i)] == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (str[(*i)] == 'p')
		{
			ft_putstr_fd("0x", 1);
			(*chars) += 2;
			put_hex_uns((unsigned long)va_arg(args, void *), 'x', 1, chars);
		}
		else if (str[(*i)] == 'd' || str[(*i)] == 'i')
			ft_putnbr_fd(va_arg(args, int), 1);
		else if (str[(*i)] == 'u')
			put_hex_uns((unsigned long)va_arg(args, unsigned int), 0, 0, chars);
		else if (str[(*i)] == 'x' || str[(*i)] == 'X')
			put_hex_uns(va_arg(args, unsigned int), str[(*i)], 1, chars);
		else if (str[(*i)] == '%')
			ft_putchar_fd('%', 1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		chars;
	va_list	args;
	va_list	args_cp;

	va_start(args, str);
	va_copy(args_cp, args);
	i = 0;
	chars = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		else
			check_specifiers(str, &i, args, &chars);
		count_chars(&chars, args_cp, str, i);
		i++;
	}
	va_end(args);
	va_end(args_cp);
	return (chars);
}
