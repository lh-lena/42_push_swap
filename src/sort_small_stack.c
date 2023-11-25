/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:48:44 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/25 17:46:08 by ohladkov         ###   ########.fr       */
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
		write(1, "sa\n", 3);
	}
	else if (size == 3)
	{
		sort_3_stack(a);
	}
	else if (size == 5)
	{
		sort_5_stack(a, b);
	}
}

void	sort_3_stack(t_list **stack_a)
{
	long	first;
	long	second;
	long	third;

	first = (*stack_a)->val;
	second = ((*stack_a)->next)->val;
	third = ((*stack_a)->prev)->val;
	if ((first > second && first < third) || (first > second && second > third && first > third) || (second > third && second > first && first < third))
	{
		sa(stack_a);
		first = (*stack_a)->val;
		second = (*stack_a)->next->val;
		write(1, "sa\n", 3);
	}
	if (first > second && second < third)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
	}
	if (first < second && third < first)
	{
		rra(stack_a);
		write(1, "rra\n", 4);
	}
}

void	sort_5_stack(t_list **a, t_list **b)
{
	t_details	data;

	while (ft_lstsize(a) > 3)
	{
		data.min = get_min(a);
		while(a != data.min)
		{
			if (a->above_median)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	write(1, "a\n", 2);
	print_lst(*a);
	write(1, "b\n", 2);
	print_lst(*b);
	sort_3_stack(a);
	write(1, "a2\n", 3);
	print_lst(*a);
}
