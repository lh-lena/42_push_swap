/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:21:11 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/30 17:41:34 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
void	sort_big_stack(t_list **a, t_list **b)
{
	// if (is_rev_sorted(a))
	// 	rev_sort(a, b);
	// t_save	save;
	// size_t	size;

	// size = ft_lstsize(*a);
	// save.i = 0;
	// while (save.i < 31)
	// {
	// 	save.k = 0;
	// 	positive_sort(a, b, &save, size);
	// 	save.i++;
	// }
	// save.k = 0;
	// negative_sort(a, b, &save, size);
	// write(1, "rb\n", 3);
}
*/

void	sort_big_stack(t_list **a, t_list **b)
{
	t_details	data;

	if (is_rev_sorted(a))
		rev_sort(a, b);
	set_cur_pos(a);
	pb(a, b);
	pb(a, b);
	data.max = get_max(*a);
	data.min = get_min(*a);
	// printf("POS MAX = %d \n", data.max->pos);
	// printf("POS MIN = %d \n", data.min->pos);
	// printf("List size = %zu\n", ft_lstsize(*a));
}
