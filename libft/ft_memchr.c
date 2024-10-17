/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteteria <hteteria@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:17:42 by hteteria          #+#    #+#             */
/*   Updated: 2024/09/21 01:17:43 by hteteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*p;

	p = NULL;
	if (!s)
		return (NULL);
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			p = (void *)s;
			break ;
		}
		s++;
		n--;
	}
	return (p);
}
