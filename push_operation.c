/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:14:23 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 12:40:53 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*toPush;
	
	toPush = *stack_b;
	if (*stack_b)
	{
		deleteFirstNode(stack_b);
		ft_add_front(stack_a, toPush);
		// ft_putendl("pa");
	}
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*toPush;

	toPush = *stack_a;
	if (*stack_a)
	{
		deleteFirstNode(stack_a);
		ft_add_front(stack_b, toPush);
		// ft_putendl("pb");
	}
}