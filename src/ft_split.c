/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:10 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_arr(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
		i++;
	while (j < i)
	{
		free(ptr[j]);
		ptr[j] = NULL;
		j++;
	}
	free(ptr);
	ptr = NULL;
}

static unsigned int	ft_words(char const *s, char c)
{
	unsigned int	nb;

	nb = 0;
	while (*s)
	{
		if (*s != c)
			nb++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (nb);
}

static char	*ft_wordalloc(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	while ((char)s[i] && (char)s[i] != c)
		i++;
	len = i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	num_words;
	size_t			i;

	num_words = ft_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			arr[i] = ft_wordalloc(s, c);
			if (!arr[i])
				return (arr);
		}
		while (*s != c && *s)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
