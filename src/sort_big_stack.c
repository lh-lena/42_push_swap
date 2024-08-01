/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:21:11 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix_sort(t_list **a, t_list **b)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	max_num = ft_lstsize(*a) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < max_num + 1)
		{
			if ((((*a)->idx >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			++j;
		}
		while (*b)
			pa(a, b);
		++i;
	}
}

void	sort_big_stack(t_list **a, t_list **b)
{
	if (is_rev_sorted(*a))
		rev_sort(a, b);
	else if (is_cyclic(*a))
		cyclic_sort(a);
	else
		radix_sort(a, b);
}
