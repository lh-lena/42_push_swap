/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:48:44 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/24 14:17:50 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small_stack(t_list **a, t_list **b)
{
	size_t	size;

	size = ft_lstsize(*a);
	// printf("stack_size = %zu\n", stack_size);
	get_max(a);
	get_min(a);
	if (size == 2)
	{
		if (!is_sorted(a))
		{
			sa(a);
			write(1, "sa\n", 3);
		}
		exit(0);
	}
	else if (size <= 5)
	{
		if (size == 3)
			sort_3_stack(a);
		sort_5_stack(a, b);
	}
}

void	sort_3_stack(t_list **stack_a)
{
	int	first;
	int	second;
	int third;

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

void	sort_5_stack(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	get_min(stack_a);
	sort_3_stack(stack_a);
	// while (ft_lstsize(*stack_b) > 0)
	// 	// *put in correct pos*
}
