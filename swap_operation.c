/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:23:10 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 13:02:11 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list **stack)
{
    t_list  *cur;
	int		temp;

    cur = (*stack);
	temp = cur->content;
	cur->content = cur->next->content;
	cur->next->content = temp;
}

//  Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
void	sa(t_list **stack_a)
{
	if (!*stack_a || (*stack_a)->next == *stack_a)
		return ;
    swap(stack_a);
    // ft_putendl("sa");
	// write(1, "sa\n", 3);
}


// Swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements.
void	sb(t_list **stack_b)
{
	if (!*stack_b || (*stack_b)->next == *stack_b)
		return ;
    swap(stack_b);
    // ft_putendl("sb");
	// write(1, "sb\n", 3);
}

//ss = sa + sb at the same time
void    ss(t_list **stack_a, t_list **stack_b)
{
    if (*stack_a || (*stack_a)->next != *stack_a)
	{
		if (*stack_b || (*stack_b)->next != *stack_b)
		{
			swap(stack_a);
			swap(stack_b);
			// ft_putendl("ss");
			write(1, "ss\n", 3);
		}
	}
}