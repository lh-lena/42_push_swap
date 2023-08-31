/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:28:24 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/29 00:45:23 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_stack(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	sort_3_stack(stack_a);
	// while (ft_lstsize(*stack_b) > 0)
	// 	// *put in correct pos*
}