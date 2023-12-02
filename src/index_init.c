/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:43:57 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/30 18:15:53 by ohladkov         ###   ########.fr       */
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
	next_min = cur;
	// printf("min = %d\n", min);
	while (size - 1)
	{
		if (cur->val <= min)
			cur = cur->next;
		if (cur->prev->val > min && cur->prev->val < cur->val)
			next_min = cur->prev;
		if (cur->val > min && cur->val < next_min->val)
			next_min = cur;
		// printf("next_min = %d\n", next_min->val);
		cur = cur->next;
		size--;
	}
	return (next_min);
}

void	fill_indexes(t_list *stack)
{
	t_list	*cur;
	size_t	size;
	int		min;
	size_t	i;

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
