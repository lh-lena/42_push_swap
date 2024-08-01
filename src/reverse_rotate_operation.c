/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:30:07 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	rra(t_list **stack_a)
{
	if (*stack_a && ft_lstsize(*stack_a) > 1)
	{
		*stack_a = (*stack_a)->prev;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	if (*stack_b && ft_lstsize(*stack_b) > 1)
	{
		*stack_b = (*stack_b)->prev;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && ft_lstsize(*stack_a) > 1)
	{
		if (*stack_b && ft_lstsize(*stack_b) > 1)
		{
			*stack_b = (*stack_b)->prev;
			*stack_a = (*stack_a)->prev;
			write(1, "rrr\n", 4);
		}
	}
}
