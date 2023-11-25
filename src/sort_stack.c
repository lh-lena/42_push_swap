/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:56:02 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/25 11:12:01 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	// printf("stack_size = %zu\n", stack_size);

	/*if (size == 2)
	{
		if (!is_sorted(stack_a))
		{
			sa(stack_a);
			write(1, "sa\n", 3);
		}
		exit(1);
	}
	else if (size == 3)
	{
		// write(1, "sort 3\n", 7);
		sort_3_stack(stack_a);
	}
	else if (size == 5)
	{
		// write(1, "sort 5\n", 7);
		sort_5_stack(stack_a, stack_b);
	}*/
	// if (is_cyclic(stack_a))
	// {
	// 	write(1, "c", 1);
	// 	exit(1);
	// }
	// else if (is_rev_sorted(stack_a))
	// {
	// 	write(1, "r", 1);
	// 	exit (1);
	// }
	if (size <= 5)
	{
		sort_small_stack(stack_a, stack_b);
	}
	else
	{
		stack_dup(*stack_a);
		sort_big_stack(stack_a, stack_b);
	}
}