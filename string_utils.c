#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	len;
	char	*s;

	len = 0;
	s = str;
	while (s[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0 || (ft_strlen((char *)s1) > ft_strlen((char *)s2)))
		return (-1);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}