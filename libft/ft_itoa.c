/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteteria <hteteria@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:17:11 by hteteria          #+#    #+#             */
/*   Updated: 2024/09/21 01:17:11 by hteteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write2string(char *str, int n, int len)
{
	str[len] = '\0';
	if (n == -2147483648)
	{
		len--;
		str[len] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		temp;
	char	*str;
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	temp = n;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	write2string(str, n, len);
	return (str);
}
