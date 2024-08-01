/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:03 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_edge(const char *s, int sign)
{
	long long	num;

	num = 0;
	if (*s == '-' || *s == '+')
	{
		if (*(s + 1) == '\0')
			return (0);
		s++;
	}
	while (*s)
	{
		num = num * 10 + (*s - 48);
		s++;
	}
	if (num * sign < INT_MIN || num * sign > INT_MAX)
		return (0);
	return (1);
}

int	is_valid(const char *s)
{
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (ft_strlen(s) >= 12)
		return (0);
	if (ft_strlen(s) >= 10)
	{
		if (check_edge(s, sign) == 0)
			return (0);
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_list *stack_a)
{
	t_list	*temp;
	t_list	*cur;

	cur = stack_a;
	while (cur != stack_a->prev)
	{
		temp = cur->next;
		while (temp != stack_a->prev->next)
		{
			if (cur->val == temp->val)
				return (1);
			temp = temp->next;
		}
		cur = cur->next;
	}
	return (0);
}
