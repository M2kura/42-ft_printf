/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteteria <hteteria@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:17:50 by hteteria          #+#    #+#             */
/*   Updated: 2024/09/21 01:17:50 by hteteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst || !src)
		return (dst);
	i = 0;
	while (n > 0)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}
