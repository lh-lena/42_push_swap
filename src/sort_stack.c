/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:56:02 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/30 18:17:31 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	size_t	size;

	size = ft_lstsize(*a);
	set_cur_pos(a);
	fill_indexes(*a);
	// print_lst(*a);
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
		pb(a, b);
		size--;
	}
	size = ft_lstsize(*b);
	while (size)
	{
		pa(a, b);
		size--;
	}
}
