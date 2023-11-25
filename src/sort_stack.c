/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:56:02 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/25 17:29:20 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	size_t	size;

	size = ft_lstsize(*a);
	set_idx(a);
	if (size <= 5)
	{
		sort_small_stack(a, b);
	}
	else
	{
		sort_big_stack(a, b);
	}
}

void	rev_sort(t_list **a, t_list **b)
{
	size_t	size;

	size = ft_lstsize(*a);
	while (size)
	{
		rra(a);
		write(1, "rra\n", 4);
		pb(a, b);
		write(1, "pb\n", 3);
		size--;
	}
	size = ft_lstsize(*b);
	while (size)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		size--;
	}
}
// if (is_cyclic(stack_a))
// {
// 	while(!is_sorted(stack_a))
// 	{
// 		rra(stack_a);
// 		write(1, "rra\n", 4);
// 	}
// }