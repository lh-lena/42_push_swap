/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:29:11 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 12:41:13 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_list **stack_a)
{
   if (*stack_a)
   {
		(*stack_a) = (*stack_a)->next;
		// ft_add_back(stack_a, cur); //to delete
		// write(1, "ra\n", 3);
   }
}

// Shift up all elements of stack b by 1. 
// The first element becomes the last one.
void	rb(t_list **stack_b)
{
	if (*stack_b)
	{
		(*stack_b) = (*stack_b)->next;
		// ft_add_back(stack_b, cur); to del
		// write(1, "rb\n", 3);
	}
}

// rr : ra and rb at the same time.

// void	ra(t_list **stack_a)
// {
// 	if (*stack_a)
// 	{
// 		*stack_a = (*stack_a)->next;
// 		ft_putendl("ra");
// 	}
// }

// void	rb(t_list **stack_b)
// {
// 	if (*stack_b)
// 	{
// 		*stack_b = (*stack_b)->next;
// 		ft_putendl("rb");
// 	}
// }

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
	{
		if (*stack_b)
		{
			*stack_b = (*stack_b)->next;
			*stack_a = (*stack_a)->next;
			// ft_putendl("rr");
			write(1, "rr\n", 3);
		}
	}
}