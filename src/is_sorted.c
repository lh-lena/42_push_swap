/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:00:35 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/17 17:32:54 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_sorted(t_list **stack)
{
	t_list	*cur;
	int		temp;
	size_t	size;

	if (!stack)
		return (1);
	cur = (*stack);
	size = ft_lstsize(*stack);
	while (size)
	{
		temp = cur->val;
		cur = cur->next;
		if (temp > cur->val)
			return (false);
		size--;
	}
	return (true);
}
