/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:10 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/25 14:15:17 by ohladkov         ###   ########.fr       */
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

int	ft_countw(char *str, char c)
{
	unsigned int	nb;
	size_t	i;
	char	*s;

	s = str;
	nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			nb++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nb);
}

char	*ft_allocwrd(char const *str, char c)
{
	char	*wrd;
	size_t	i;
	size_t	len;

	i = 0;
	while ((char)str[i] && (char)str[i] != c)
		i++;
	len = i;
	wrd = (char *)malloc(sizeof(char) * (len + 1));
	if (wrd == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		wrd[i] = (char)str[i];
		i++;
	}
	wrd[i] = '\0';
	return (wrd);
}

char	**ft_split(char *str, char c)
{
	int	i;
	int	wrds;
	char	**arr;

	if (str == NULL)
		return (NULL);
	wrds = ft_countw(str, c);
	if (!wrds)
		exit (1);
	i = 0;
	arr = (char **)malloc(sizeof(char *) * (wrds + 1));
	if (arr == NULL)
		return (NULL);
	while (i < wrds)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			arr[i] = ft_allocwrd(str, c);
			if (!arr[i])
				return (arr);
		}
		while (*str && *str != c)
			str++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}