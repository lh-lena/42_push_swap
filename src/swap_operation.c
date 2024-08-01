/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:23:10 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_nodes(t_list **stack)
{
	t_list	*cur;
	int		temp;
	int		idx_t;

	cur = (*stack);
	temp = cur->val;
	idx_t = cur->idx;
	cur->val = cur->next->val;
	cur->idx = cur->next->idx;
	cur->next->val = temp;
	cur->next->idx = idx_t;
}

/* Swap the first 2 elements at the top of stack a. 
Do nothing if there is only one or no elements. */
void	sa(t_list **stack_a)
{
	if (!*stack_a || (*stack_a)->next == *stack_a)
		return ;
	swap_nodes(stack_a);
	write(1, "sa\n", 3);
}

/* Swap the first 2 elements at the top of stack b. 
Do nothing if there is only one or no elements. */
void	sb(t_list **stack_b)
{
	if (!*stack_b || (*stack_b)->next == *stack_b)
		return ;
	swap_nodes(stack_b);
	write(1, "sb\n", 3);
}

// ss = sa + sb at the same time
void	ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a || (*stack_a)->next != *stack_a)
	{
		if (*stack_b || (*stack_b)->next != *stack_b)
		{
			swap_nodes(stack_a);
			swap_nodes(stack_b);
			write(1, "ss\n", 3);
		}
	}
}
