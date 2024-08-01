/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:38:41 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:21:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *head)
{
	return (head->prev);
}

size_t	ft_lstsize(t_list *lst)
{
	void	*last_node;
	size_t	i;

	if (!lst)
		return (0);
	last_node = lst;
	i = 1;
	while (lst->next != last_node)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*get_max(t_list *stack)
{
	t_list	*max;
	t_list	*cur;
	int		size;
	long	temp;

	size = ft_lstsize(stack);
	cur = stack;
	max = cur;
	while (size)
	{
		temp = cur->val;
		cur = cur->next;
		if (max->val < temp)
			max = cur->prev;
		size--;
	}
	return (max);
}

t_list	*get_min(t_list *stack)
{
	t_list	*min;
	t_list	*cur;
	int		size;
	long	temp;

	size = ft_lstsize(stack);
	cur = stack;
	min = cur;
	while (size)
	{
		temp = cur->val;
		cur = cur->next;
		if (min->val > temp)
			min = cur->prev;
		size--;
	}
	return (min);
}

void	set_cur_pos(t_list *stack)
{
	int		i;
	int		median;
	size_t	size;
	t_list	*cur;

	if (!stack)
		return ;
	cur = stack;
	i = 0;
	size = ft_lstsize(stack);
	median = size / 2;
	while (size)
	{
		cur->pos = i;
		if (i <= median)
			cur->above_median = 1;
		else
			cur->above_median = 0;
		cur = cur->next;
		i++;
		size--;
	}
}
