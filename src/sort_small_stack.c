/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:48:44 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/25 19:31:33 by ohladkov         ###   ########.fr       */
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
	else if (size <= 5)
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
	}
	if (first > second && second < third)
	{
		ra(stack_a);
	}
	if (first < second && third < first)
	{
		rra(stack_a);
	}
}

static bool	check(int a, int b)
{
	if (a == b)
		return (1);
	return (0);
}

void	sort_5_stack(t_list **a, t_list **b)
{
	t_details	data;
	size_t		size;

	size = ft_lstsize(*a);
	while (size-- > 3)
	{
		data.min = get_min(a);
		while(!check((*a)->val, data.min->val))
		{
			if (data.min->above_median)
			{
				ra(a);
			}
			else
			{
				rra(a);
			}
		}
		pb(a, b);
		write(1, "pb\n", 3);
	}
	sort_3_stack(a);
	pa(a, b);
	pa(a, b);
}


