/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:43:57 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_next_min(t_list *stack, int min)
{
	t_list	*next_min;
	t_list	*cur;
	size_t	size;

	size = ft_lstsize(stack);
	cur = stack;
	while (cur->val <= min)
		cur = cur->next;
	next_min = cur;
	while (size - 1)
	{
		if (cur->val <= min)
			cur = cur->next;
		if (cur->val > min && cur->val < next_min->val)
			next_min = cur;
		cur = cur->next;
		size--;
	}
	return (next_min);
}

void	fill_indexes(t_list *stack)
{
	t_list	*cur;
	int		size;
	int		min;
	int		i;

	size = ft_lstsize(stack);
	cur = get_min(stack);
	cur->idx = 0;
	min = cur->val;
	i = 1;
	while (i < size)
	{
		cur = get_next_min(stack, min);
		cur->idx = i;
		min = cur->val;
		i++;
	}
}
