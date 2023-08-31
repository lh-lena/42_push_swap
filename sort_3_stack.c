/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:48:44 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 14:16:11 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_3_stack(t_list **stack_a)
{
	int	first;
	int	second;
	int third;

	first = (*stack_a)->content;
	second = ((*stack_a)->next)->content;
	third = ((*stack_a)->prev)->content;
	if ((first > second && first < third) || (first > second && second > third && first > third) || (second > third && second > first && first < third))
	{
		sa(stack_a);
		first = (*stack_a)->content;
		second = (*stack_a)->next->content;
		write(1, "sa\n", 3);
	}
	if (first > second && second < third)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
	}
	if (first < second && third < first)
	{
		rra(stack_a);
		write(1, "rra\n", 4);
	}
}

// void	sortThree(t_list **stack_a)
// {
// 	int	first;
// 	int	second;
// 	int	third;

// 	first = (*stack_a)->data;
// 	second = (*stack_a)->next->data;
// 	third = ft_lstlast(*stack_a)->data;
// 	if ((first > second && first < third && second < third)
// 		|| (first > second && first > third && second > third)
// 		|| (first < second && second > third && first < third)
// 		|| (first > second && second == third))
// 	{
// 		sa(stack_a);
// 		first = (*stack_a)->data;
// 		second = (*stack_a)->next->data;
// 	}
// 	if (third < first && first < second)
// 		rra(stack_a);
// 	if (first > second && second < third)
// 		ra(stack_a);
// }