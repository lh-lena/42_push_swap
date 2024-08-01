/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:00:35 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/17 17:32:54 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*cur;
	int		temp;

	if (!stack)
		return (1);
	cur = stack;
	while (cur->next != stack)
	{
		temp = cur->val;
		cur = cur->next;
		if (temp > cur->val)
			return (0);
	}
	return (1);
}

int	is_cyclic(t_list *stack)
{
	t_details	data;
	int			temp;

	data.min = get_min(stack);
	data.max = get_max(stack);
	if (data.min->prev->val == data.max->val)
	{
		while (data.min->next != data.max)
		{
			temp = data.min->val;
			data.min = data.min->next;
			if (temp > data.min->val)
			{
				return (0);
			}
		}
		return (1);
	}
	else
		return (0);
	return (1);
}

int	is_rev_sorted(t_list *stack)
{
	t_list	*cur;
	int		temp;

	cur = stack;
	while (cur->next != stack)
	{
		temp = cur->val;
		cur = cur->next;
		if (temp < cur->val)
			return (0);
	}
	return (1);
}
