/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:03 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 15:08:38 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// is 0-9
int ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// is alphanumerical char (except '+' '-')
// int	ft_isalpha(int c)
// {
// 	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
// 		|| (c == 44) || (c == 46) || (c == 47))
// 		return (1);
// 	return (0);
// }

// check edge cases
// int	check_edge(char *s)
// {
// 	int		len;
// 	char	*str;
// 	char	*min;
// 	char	*max;

// 	if (!ft_isdigit(*s) || *s != '-' || *s != '+')
// 		return (-1);
// 	len = ft_strlen(s);
// 	str = s;
// 	min = "-2147483648";
// 	max = "2147483647";
// 	printf("ft_strncmp(str, min, len) = %i\n ft_strncmp(str, max, len) = %i\n", ft_strncmp(str, min, len), ft_strncmp(str, max, len));
// 	if (*str == '-')
// 	{
// 		if (ft_strncmp(str, min, len) > 0)
// 			return (-2);
// 	}
// 	else
// 	{
// 		//printf("ft_strncmp(str, max, len) = %i\n", ft_strncmp(str, max, len));
// 		if (ft_strncmp(str, max, len) > 0)
// 			return (-3);
// 	}
// 	return (1);
// }

// // check -[0-9] +[0-9]
// int check_digit(char *s)
// {
//     size_t	i;
// 	char	*str;
// 	size_t	len;

// 	str = s;
// 	len = ft_strlen(s);
// 	i = 0;
// 	if (str[i] && (str[i] == '-' || str[i] == '+'))
// 		i++;
//     while (str[i])
//     {
//         if (!ft_isdigit(str[i]))
// 			return (-4);
//         i++;
//     }
// 	if (len > 11)
// 		return (-3);
// 	if (len > 9 && len < 12)
// 	{
// 		if (!check_edge(s))
// 			return (-5);
// 	}
//     return (1);
// }
bool	check_edge(const char *s, int sign)
{
	long long	num;

	num = 0;
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		// if (!ft_isdigit(*s))
		// 	return (false);
		num = num * 10 + (*s - 48);
		s++;
	}
	if (num * sign < INT_MIN || num * sign > INT_MAX)
		return (false);
	return (true);
}

bool	check_digit(const char *s)
{
	int		sign;
	size_t	len;
	char 	*str;
	int		i;

	sign = 1;
	len = ft_strlen((char *)s);
	i = 0;
	str = (char *)s;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	len = ft_strlen(str);
	if (len >= 12)
		return (false);
	if (len >= 10)
	{
		if (check_edge(str, sign) == false)
			return (false);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

// void	check_args(int argc, char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (!check_digit(argv[i]))
// 			display_error();
// 		i++;
// 	}
// }


// check duplicates
bool	check_duplicate(t_list **stack_a)
{
	t_list	*temp;
	t_list	*cur;

	cur = (*stack_a);
	while (cur != (*stack_a)->prev)
	{
		temp = cur->next;
		while (temp != (*stack_a)->prev->next)
		{
			if (cur->content == temp->content)
			{
				write(1, "duplicate\n", 10);
				return (true);
			}
			temp = temp->next;
		}
		cur = cur->next;
	}
	return (false);
}


