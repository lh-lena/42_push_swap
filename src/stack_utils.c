/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:38:41 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/25 18:47:45 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list *stack, void	*last)
{
	if ((void*)stack == NULL || !stack)
	{
		printf("Stack empty\n");
		return ;
	}
	if (stack)
	{
		if (stack != last)
			free_stack(stack->next, last);
		free(stack);
	}
}

t_list	*ft_lstlast(t_list *head)
{
	// printf("head->prev = %i\n", head->prev);
	return (head->prev);
}

size_t	ft_lstsize(t_list *lst)
{
	void	*last_node;
	size_t		i;

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

void	print_lst(t_list *lst)
{
	t_list	*temp;
	size_t	size;
	size_t		i;
	
	i = 0;
	temp = lst;
	size = ft_lstsize(lst);
	while (i < size)
	{
		printf(" node = %d |\n", temp->val);
		temp = temp->next;
		i++;
	}
	if (lst == NULL)
		printf("lst = NULL\n");
}

t_list *get_max(t_list **stack)
{
	t_list *max;
	int		size;
	t_list	*cur;
	long	temp;

	size = ft_lstsize(*stack);
	cur = (*stack);
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

t_list *get_min(t_list **stack)
{
	t_list *min;
	int		size;
	t_list	*cur;
	long	temp;

	size = ft_lstsize(*stack);
	cur = (*stack);
	min = cur;
	while (size)
	{
		temp = cur->val;
		cur = cur->next;
		if (min->val > temp)
			min = cur->prev;
		size--;
	}
	// printf("MIN = %d\n", min->val);
	return (min);
}

void	set_idx(t_list **stack)
{
	int		i;
	int		median;
	size_t	size;
	t_list	*cur;

	if (!stack)	
		return ;
	cur = *stack;
	i = 0;
	size = ft_lstsize(*stack);
	median = size / 2;
	while (size)
	{
		cur->idx = i;
		if (i <= median)
			cur->above_median = true;
		else
			cur->above_median = false;
		cur = cur->next;
		// ++i;
		i++;
		size--;
	}
}