/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:00:35 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 10:48:18 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sorted(t_list **stack_a)
{
	int	size;
	t_list	*cur;
	int		temp;

	size = ft_lstsize(*stack_a);
	cur = (*stack_a);
	while (--size)
	{
		
		temp = cur->content;
		cur = cur->next;
		if (temp > cur->content)
			return (false);
	}
	return (true);
}