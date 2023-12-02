/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:48:44 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/30 13:28:43 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small_stack(t_list **a, t_list **b)
{
	size_t	size;

	size = ft_lstsize(*a);
	if (size == 2)
	{
		sa(a);
	}
	else if (size == 3)
	{
		sort_three_stack(a);
	}
	else if (size == 5 || size == 4)
	{
		sort_five_stack(a, b);
	}
}

void	sort_three_stack(t_list **stack_a)
{
	t_details	data;

	if (is_sorted(stack_a))
		return ;
	data.max = get_max(*stack_a);
	if (data.max->val == (*stack_a)->val)
		ra(stack_a);
	else if (data.max->val == (*stack_a)->next->val)
		rra(stack_a);
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a);
}

static bool	equal(int a, int b)
{
	if (a == b)
		return (1);
	return (0);
}

void	sort_five_stack(t_list **a, t_list **b)
{
	t_details	data;
	size_t		size;

	size = ft_lstsize(*a);
	while (size-- > 3)
	{
		set_cur_pos(a);
		data.min = get_min(*a);
		while (!equal((*a)->val, data.min->val))
		{
			if (data.min->above_median)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_three_stack(a);
	pa(a, b);
	pa(a, b);
}
