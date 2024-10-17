/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteteria <hteteria@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:19:04 by hteteria          #+#    #+#             */
/*   Updated: 2024/09/21 01:19:05 by hteteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	end(char const *str, char const *set, const size_t len)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, str[len - 1 - i]) != NULL)
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;
	size_t	strt;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	strt = start(s1, set);
	if (strt == len)
		size = 0;
	else
		size = len - strt - end(s1, set, len);
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while (len < size)
	{
		ptr[len] = s1[strt + len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}
