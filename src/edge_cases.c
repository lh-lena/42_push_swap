/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:09:29 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/25 15:05:49 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	is_cyclic(t_list **stack)
// {
// 	t_details	data;
// 	t_list		*cur;

// 	cur = (*stack);
// 	data.min = get_min(stack);
// 	data.max = get_max(stack);
// 	data.upward = 0;
// 	data.downward = 0;
// 	while (cur->next != stack)
// 	{
// 		if (cur->val > cur->next->val)
// 			downward++;
// 		else if (cur->val < cur->next->val)
// 			upward++;
// 		cur = cur->next;
// 	}
// 	if (cur->val > cur->next->val)
// 		downward++;
// 	else if (cur->val < cur->next->val)
// 		downward++;
// 	if (upward > 0 && downward > 0)
// 		return (1);
// 	else
// 		return (0);
// }

// int	is_cyclic(t_list **stack)
// {
// 	t_details	data;
// 	int			temp;

// 	data.min = get_min(stack);
// 	data.max = get_max(stack);
// 	while (data.min->next != data.max)
// 	{
// 		temp = data.min->val;
// 		data.min = data.min->next;
// 		if (temp > data.min->val)
// 		{
// 			return (0);
// 		}
// 	}
// 	return (1);
// } //stuck when rev_sort

int	is_cyclic(t_list **stack)
{
	t_details	data;
	// t_list		*cur;
	int			temp;

	// cur = *stack;
	data.min = get_min(stack);
	data.max = get_max(stack);
	data.upward = 0;
	data.downward = 0;
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

int	is_rev_sorted(t_list **stack)
{
	t_list	*cur;
	int		temp;

	cur = (*stack);
	while (cur->next != *stack)
	{
		temp = cur->val;
		cur = cur->next;
		if (temp < cur->val)
			return (0);
	}
	return (1);
}
