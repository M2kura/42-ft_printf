/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteteria <hteteria@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 01:18:13 by hteteria          #+#    #+#             */
/*   Updated: 2024/09/21 01:18:19 by hteteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*fill_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	*free_memory(char **ptr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	ptr[count_words(s, c)] = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			ptr[i] = fill_word(s, c);
			if (ptr[i] == NULL)
				return (free_memory(ptr, i));
			i++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (ptr);
}
