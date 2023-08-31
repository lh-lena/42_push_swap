/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:56:02 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/29 00:09:19 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*stack_a);
	// printf("stack_size = %zu\n", stack_size);

	if (stack_size == 2)
	{
		if (!check_sorted(stack_a))
		{
			sa(stack_a);
			write(1, "sa\n", 3);
		}
		exit(1);
	}
	else if (stack_size == 3)
	{
		// write(1, "sort 3\n", 7);
		sort_3_stack(stack_a);
	}
	else if (stack_size == 5)
	{
		// write(1, "sort 5\n", 7);
		sort_5_stack(stack_a, stack_b);
	}
	// else
	// {
	//     write(1, "sort big\n", 9);
	//     sort_big_stack(stack_a);
	// }
}