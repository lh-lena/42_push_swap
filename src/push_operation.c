/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:14:23 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/26 11:48:41 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*push;

	push = *stack_b;
	if (*stack_b)
	{
		delete_first_node(stack_b);
		ft_add_front(stack_a, push);
		write(1, "pa\n", 3);
	}
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*push;

	push = *stack_a;
	if (*stack_a)
	{
		delete_first_node(stack_a);
		ft_add_front(stack_b, push);
		write(1, "pb\n", 3);
	}
}
