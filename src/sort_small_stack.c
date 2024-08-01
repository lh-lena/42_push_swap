/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:48:44 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
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

	if (is_sorted(*stack_a))
		return ;
	data.max = get_max(*stack_a);
	if (data.max->val == (*stack_a)->val)
		ra(stack_a);
	else if (data.max->val == (*stack_a)->next->val)
		rra(stack_a);
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a);
}

void	sort_five_stack(t_list **a, t_list **b)
{
	size_t		size;

	size = ft_lstsize(*a);
	while (size-- > 3)
	{
		while ((*a)->val != get_min(*a)->val)
		{
			if (get_min(*a)->above_median)
				ra(a);
			else
				rra(a);
			set_cur_pos(*a);
		}
		pb(a, b);
	}
	sort_three_stack(a);
	pa(a, b);
	pa(a, b);
}
