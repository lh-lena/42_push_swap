/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:09:29 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/24 14:42:12 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_cyclic(t_list **stack)
{
	t_details	data;
	t_list		*cur;

	cur = (*stack);
	data.min = get_min(stack);
	data.max = get_max(stack);
	data.c_upward = 0;
	data.c_downward = 0;
	while (cur->next != stack)
	{
		if (cur->val > cur->next->val)
			c_downward++;
		else if (cur->val < cur->next->val)
			c_upward++;
		cur = cur->next;
	}
	if (cur->val > cur->next->val)
		c_downward++;
	else if (cur->val < cur->next->val)
		c_downward++;
	if (c_upward > 0 && c_downward > 0)
		return (1);
	else
		return (0);
}

int	is_rev_sorted(t_list **stack)
{
	t_list	*cur;
	int		temp;

	cur = (*stack);
	while (cur->next != stack)
	{
		temp = cur->val;
		cur = cur->next;
		if (temp < cur->val)
			return (0);
	}
	return (1);
}
